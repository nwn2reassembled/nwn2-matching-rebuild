// NWN2RulesLib.dll, RVA 0x2e6d0

// Simple integral constant accessor; called with no arguments (bare RET,
// callee does not pop any stack space) and returns a plain value in EAX,
// consistent with __cdecl or a zero-argument __stdcall export.
// 0x791 = 1937.

unsigned int __stdcall GetRulesVersionBuild()
{
    return 1937u;
}
