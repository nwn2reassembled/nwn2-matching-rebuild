int ClearSlot(void* pItems, unsigned int index)
{
    unsigned char* base = static_cast<unsigned char*>(pItems);
    base[index * 8 + 0xa8] = 0;
    *reinterpret_cast<unsigned long*>(base + index * 8 + 0xac) = 0;
    return 0;
}
