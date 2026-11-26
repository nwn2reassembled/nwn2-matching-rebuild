struct ByteMaskObject
{
    unsigned char padding[0x2fc];
    unsigned char value;

    unsigned int AndWith(unsigned char mask);
};

unsigned int ByteMaskObject::AndWith(unsigned char mask)
{
    return value & mask;
}
