struct CRulesTable {
    unsigned char pad0[8];
    unsigned char flags[2];
};

unsigned char __stdcall GetFlag(const CRulesTable *table, unsigned char index)
{
    if (index < 2)
        return table->flags[index];
    return (unsigned char)-1;
}
