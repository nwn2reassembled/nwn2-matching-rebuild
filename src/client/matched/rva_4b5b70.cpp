struct NwnSearch {
    unsigned char padding[0x28];
    unsigned short values[10];
    unsigned char Find(unsigned short value);
};

unsigned char NwnSearch::Find(unsigned short value)
{
    if (value != 0xFFFF) {
        for (unsigned char i = 0; i < 10; ++i) {
            if (values[i] == value)
                return i;
        }
    }
    return 0xFF;
}
