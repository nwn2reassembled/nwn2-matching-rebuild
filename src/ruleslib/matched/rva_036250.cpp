// NWN2RulesLib.dll RVA 0x36250

struct RuleTable
{
    char data[0x294];
    int count;
};

int __stdcall RuleTable_IsIndexValid(RuleTable* table, int index)
{
    if (index >= 0 && index < table->count)
        return 1;
    return 0;
}
