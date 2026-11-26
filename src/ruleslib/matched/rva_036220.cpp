struct CRuleTable {
    unsigned char pad0[0x28c];
    int count;
};

int __stdcall IsIndexValid(CRuleTable* table, int index) {
    if (index >= 0 && index < table->count)
        return 1;
    return 0;
}
