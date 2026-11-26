void __cdecl accumulate(unsigned int* total, const unsigned char* base, unsigned int count)
{
    unsigned int amount = *(const unsigned int*)(base + 0x112) * count
                       / *(const unsigned int*)(base + 0x116);
    *total += amount;
}
