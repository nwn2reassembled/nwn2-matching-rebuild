struct Table
{
    unsigned char reserved[0x94];
    unsigned long values[41];
};

unsigned long __stdcall LookupValue(const Table* table, unsigned char index)
{
    if (index <= 0x28)
        return table->values[index];

    return 0;
}
