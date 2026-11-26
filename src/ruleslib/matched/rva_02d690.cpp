// NWN2RulesLib.dll RVA 0x2D690

// Plain zero-argument function returning a fixed rules-version value.
// The compiled body is a constant load into eax plus a bare ret, so no
// argument or object is passed in registers or cleaned from the stack.

int GetRulesEngineVersion()
{
    const int rulesEngineVersion = 0x68D; // 1677
    return rulesEngineVersion;
}
