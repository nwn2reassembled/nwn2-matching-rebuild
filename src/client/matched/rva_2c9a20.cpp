struct BitArray
{
    unsigned long pad0[14];          // +0x00 .. +0x34
    unsigned long count;             // +0x38 number of valid indices
    unsigned char* flags;            // +0x3C flag bytes, indexed by index
    unsigned char pad44[0x0C];       // +0x40 .. +0x48
    unsigned char* values;           // +0x4C value bytes, indexed by index

    unsigned char Set(unsigned long index, unsigned char value);
};

unsigned char BitArray::Set(unsigned long index, unsigned char value)
{
    if (index < count)
    {
        unsigned char v = value;

        if (flags[index] != 0)
        {
            if (v == 1)
            {
                values[index] = v;
                return v;
            }
        }

        if (v == 0)
        {
            values[index] = 0;
            return 1;
        }
    }

    return 0;
}
