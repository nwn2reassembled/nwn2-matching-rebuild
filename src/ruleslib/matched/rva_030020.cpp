struct LookupTable {
    unsigned char pad[18];
    unsigned short values[6];
};

unsigned int __stdcall LookupTable_GetValue(LookupTable *table, unsigned char index)
{
    if (index < 6)
    {
        return table->values[index];
    }
    return 0xFFFF;
}
