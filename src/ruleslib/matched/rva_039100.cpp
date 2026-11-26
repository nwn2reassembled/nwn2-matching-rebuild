struct RuleEntry {
    unsigned short first;
    unsigned short second;
    unsigned short third;
    unsigned short fourth;
    unsigned short fifth;
    unsigned short sixth;
};

struct RuleTable {
    unsigned char pad[0x14];
    RuleEntry entries[1];
};

unsigned int __stdcall GetEntryWord(RuleTable* table, unsigned char index) {
    if (index < 10) {
        return table->entries[index].first;
    }
    return 0;
}
