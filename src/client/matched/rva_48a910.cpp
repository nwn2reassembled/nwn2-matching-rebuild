struct Legacy
{
    unsigned char padding[0xD0];
    unsigned int multiplier;
    unsigned int *arrayPtr;

    unsigned short func(unsigned short a, unsigned short b) const;
};

unsigned short Legacy::func(unsigned short a, unsigned short b) const
{
    unsigned int prod = multiplier * static_cast<unsigned int>(a);
    unsigned int idx  = prod + static_cast<unsigned int>(b);
    return *reinterpret_cast<const unsigned short*>(
        reinterpret_cast<const unsigned char*>(arrayPtr) + idx*8 );
}

