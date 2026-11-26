unsigned int SetFlag(unsigned char* obj, unsigned int value)
{
    unsigned int old = *(unsigned int*)(obj + 0xCF);
    *(unsigned int*)(obj + 0xCF) = value;
    return old;
}
