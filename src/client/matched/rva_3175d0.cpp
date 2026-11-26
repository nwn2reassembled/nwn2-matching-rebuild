struct LookupTable {
    unsigned short count;
    unsigned short field02;
    unsigned int field04;
    const char* table;

    char GetEntry(unsigned short index);
};

char LookupTable::GetEntry(unsigned short index) {
    if (index >= count)
        return 0;
    return table[index];
}
