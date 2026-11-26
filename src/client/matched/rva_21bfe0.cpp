struct ByteStore
{
    char padding[0x5cb];
    unsigned char values[9];

    void set(unsigned char index, unsigned char value);
};

void ByteStore::set(unsigned char index, unsigned char value)
{
    if (index < 9)
        values[index] = value;
}
