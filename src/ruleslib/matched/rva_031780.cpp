struct ValueTable
{
    unsigned char reserved[0xd4];
    unsigned char values[40];
};

unsigned char __stdcall GetTableValue(const ValueTable* table, unsigned char index)
{
    if (index < 40)
        return table->values[index];

    return 0;
}
