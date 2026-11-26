struct StridedBlock
{
    unsigned char head[0x14];             // 0x000..0x013
    unsigned char count;                  // 0x014
    unsigned char gap[0x112 - 0x15];      // 0x015..0x111
    unsigned char firstItem;              // 0x112
    unsigned char itemPad[0x124 - 0x113]; // stride 0x124

    unsigned int SumItems();
};

unsigned int StridedBlock::SumItems()
{
    unsigned int total = 0;
    int n = count;
    if (n > 0)
    {
        unsigned char* p = &firstItem;
        do
        {
            total += *p;
            p += 0x124;
            --n;
        } while (n != 0);
    }
    return total;
}
