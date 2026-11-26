struct Buffer {
    char pad[0x55d];
    unsigned char table[0x29];

    unsigned char get(unsigned char index) const;
};

unsigned char Buffer::get(unsigned char index) const
{
    if ((unsigned char)(index - 1) <= 0x27)
        return table[index];

    return 0;
}
