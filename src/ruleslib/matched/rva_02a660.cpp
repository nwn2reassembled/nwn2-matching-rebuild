// NWN2RulesLib.dll, RVA 0x2A660
// void* / int returning constant via eax, then a plain ret (callee-cleaned => __stdcall)

// Returns a fixed size/count value (876 = 0x36C), e.g. the size of a
// rules-engine structure or a table capacity queried by callers.
int __stdcall GetRuleInfoSize(void)
{
    return 876;
}
