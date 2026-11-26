int IsFlagSet(const void* pObj)
{
    const unsigned char* p = (const unsigned char*)pObj;
    return p[0] & 0x2;
}
