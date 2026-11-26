bool __cdecl IsFieldEmpty16(void* pObj)
{
    return *(unsigned short*)((char*)pObj + 0x14) == 0;
}
