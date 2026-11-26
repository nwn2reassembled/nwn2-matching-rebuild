struct Container
{
    unsigned char pad_0000[0x52c];
    int* entries;
    unsigned char pad_0530[0x8];
    int writeIndex;

    void WriteEntry(int value);
};

void Container::WriteEntry(int value)
{
    int index = this->writeIndex;
    if (index >= 0)
    {
        this->entries[index * 5 + 4] = value;
    }
}
