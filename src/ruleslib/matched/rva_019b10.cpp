unsigned char __cdecl IsBaseClassCategory(unsigned int nId)
{
    if (nId >= 0x3F1u && nId < 0x48Au)
        return 1;
    if (nId >= 0x48Au && nId < 0x4BEu)
        return 2;
    return 0;
}
