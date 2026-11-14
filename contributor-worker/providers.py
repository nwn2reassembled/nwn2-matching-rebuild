"""Bounded provider drafting; credentials never enter prompts or receipts."""
import json
import os
import re
import urllib.error
import urllib.request


class ProviderError(RuntimeError):
    pass


class TokenBudgetExhausted(ProviderError):
    pass


PROVIDERS = {
    'openai': ('https://api.openai.com/v1/chat/completions', 'OPENAI_API_KEY'),
    'anthropic': ('https://api.anthropic.com/v1/messages', 'ANTHROPIC_API_KEY'),
    'deepseek': ('https://api.deepseek.com/chat/completions', 'DEEPSEEK_API_KEY'),
}


class NoRedirect(urllib.request.HTTPRedirectHandler):
    def redirect_request(self, req, fp, code, msg, headers, newurl):
        raise ProviderError('Provider redirect rejected; credentials were not forwarded')


def generate(provider, model, prompt, max_tokens=4096, timeout=900):
    """One paid request, no automatic retries or token-exhaustion continuation."""
    if provider not in PROVIDERS or not isinstance(model, str) or not model.strip():
        raise ValueError('Select openai/anthropic/deepseek and an explicit model')
    if not isinstance(max_tokens, int) or isinstance(max_tokens, bool) or not 256 <= max_tokens <= 16384:
        raise ValueError('max_tokens must be an integer between256 and16384')
    if not isinstance(prompt, str) or not 1 <= len(prompt) <= 100000:
        raise ValueError('Prompt must contain1..100000 characters')
    url, key_name = PROVIDERS[provider]
    key = os.environ.get(key_name, '').strip()
    if not key:
        raise ProviderError(f'Set {key_name} in the process environment; never put it in task files')
    if key in prompt:
        raise ProviderError('Credential detected in prompt; refusing to send or save it')
    messages = [{'role': 'user', 'content': prompt}]
    headers = {'Content-Type': 'application/json'}
    if provider in ('openai', 'deepseek'):
        headers['Authorization'] = 'Bearer ' + key
        token_field = 'max_completion_tokens' if provider == 'openai' else 'max_tokens'
        payload = {'model': model, 'messages': messages, token_field: max_tokens}
    else:
        headers.update({'x-api-key': key, 'anthropic-version': '2023-06-01'})
        payload = {'model': model, 'messages': messages, 'max_tokens': max_tokens}
    request = urllib.request.Request(url, data=json.dumps(payload).encode(), headers=headers, method='POST')
    try:
        # Redirects are rejected instead of sending authentication to another host.
        with urllib.request.build_opener(NoRedirect()).open(request, timeout=timeout) as response:
            raw = response.read(2_000_001)
    except urllib.error.HTTPError as exc:
        raise ProviderError(f'Provider HTTP{exc.code}; no retry. Error body omitted to avoid leaking secrets') from None
    except (urllib.error.URLError, TimeoutError, OSError):
        raise ProviderError('Provider connection failed; no automatic retry') from None
    if len(raw) > 2_000_000:
        raise ProviderError('Provider response exceeded size limit; no continuation')
    if key.encode() in raw:
        raise ProviderError('Credential echoed in provider response; refusing to persist it')
    try:
        data = json.loads(raw)
        if provider in ('openai', 'deepseek'):
            choice = data['choices'][0]
            stop_reason = choice['finish_reason']
            text = choice['message']['content']
            usage_names = ('prompt_tokens', 'completion_tokens', 'total_tokens')
        else:
            stop_reason = data['stop_reason']
            if any(block.get('type') not in ('text', 'thinking', 'redacted_thinking') for block in data['content']):
                raise ProviderError('Tool/function calls are not permitted in the source-only worker')
            text = ''.join(block['text'] for block in data['content'] if block.get('type') == 'text')
            usage_names = ('input_tokens', 'output_tokens', 'cache_creation_input_tokens', 'cache_read_input_tokens')
        if stop_reason in ('length', 'max_tokens'):
            raise TokenBudgetExhausted('Output budget exhausted; do not continue or reset this request')
        if stop_reason not in ('stop', 'end_turn'):
            raise ProviderError('Provider did not finish a source-only turn; no automatic continuation')
        if not isinstance(text, str):
            raise ProviderError('Provider returned no source text')
        text = text.strip()
        if text.startswith('```'):
            match = re.fullmatch(r'```(?:json)?\s*\n?(.*?)\n?```', text, re.S)
            if not match:
                raise ProviderError('Expected one complete JSON source submission')
            text = match[1]
        submission = json.loads(text)
        if not isinstance(submission, dict) or not isinstance(submission.get('source'), str):
            raise ProviderError('Expected a JSON object with source string')
        if not 1 <= len(submission['source']) <= 12000:
            raise ProviderError('Source size exceeded the declared bounded lane')
        usage = {name: value for name in usage_names
                 if isinstance((value := data.get('usage', {}).get(name)), int)
                 and not isinstance(value, bool) and value >= 0}
        return {'source': submission['source'], 'provider': provider, 'model': model,
                'stop_reason': stop_reason, 'usage': usage, 'credentials_recorded': False}
    except (KeyError, IndexError, TypeError, ValueError):
        raise ProviderError('Malformed provider response; body omitted and no automatic retry') from None
