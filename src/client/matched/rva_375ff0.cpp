struct ValueTable
{
    char reserved[0x9ac];
    unsigned int* values;
    unsigned char count;

    void SetAt(unsigned char index, unsigned int value);
};

void ValueTable::SetAt(unsigned char index, unsigned int value)
{
    if (index < count)
        values[index] = value;
}
