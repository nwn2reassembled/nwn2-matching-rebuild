// NWN2RulesLib.dll RVA 0x2C4B0, 6 bytes: mov eax,0x569 / ret

// ABI: cdecl (no stack cleanup after ret; eax = return value;
// no arguments are read, and the body is a pure constant).
// 0x569 = 1385, plausibly a rules constant (e.g. a base XP or
// class/table identifier) returned by a lookup helper.

int GetRulesConstant1385()
{
    return 1385;
}
