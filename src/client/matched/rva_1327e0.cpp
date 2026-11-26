bool IsFlag2Set(const void* pObj)
{
    unsigned char flags = *(const unsigned char*)((const char*)pObj + 0x15);
    return (flags & 0x2) == 0x2;
}
