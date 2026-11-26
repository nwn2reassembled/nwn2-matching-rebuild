void* __cdecl IsSlotActive(void* base, int idx)
{
    if (*(unsigned long*)((char*)base + idx * 4 + 0x390) == 0)
    {
        if (*(unsigned long*)((char*)base + idx * 4 + 0x384) == 0)
            return 0;
    }

    return (char*)base + idx * 0x101 + 0x80;
}
