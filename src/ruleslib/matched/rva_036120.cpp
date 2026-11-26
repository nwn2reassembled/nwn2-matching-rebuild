struct RuleEntry
{
    unsigned char unknown00[0x80];
    int field80;
    int field84;
    unsigned char unknown88[0xB4 - 0x88];
};

struct RuleTable
{
    unsigned char unknown000[0x140];
    RuleEntry* entries;
    unsigned char unknown144[0x154 - 0x144];
    unsigned short count;
};

int __stdcall IsRuleEntryAvailable(RuleTable* table, unsigned short index)
{
    if (index < table->count)
    {
        RuleEntry* entry = &table->entries[index];
        if (entry->field84 == 0 && entry->field80 != 0)
            return 1;
    }
    return 0;
}
