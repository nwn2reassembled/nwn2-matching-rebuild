unsigned char* __cdecl GetSlotData(unsigned char* pBase, int nIndex)
{
    unsigned int* pCount = (unsigned int*)(pBase + 0x390);
    unsigned int* pFlags = (unsigned int*)(pBase + 0x384);

    if (pCount[nIndex] == 0 && pFlags[nIndex] == 0)
        return 0;

    return pBase + nIndex * 0x101 + 0x80;
}
