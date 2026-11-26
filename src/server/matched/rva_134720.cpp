char* ResolveContainer(char* pObj)
{
    if (*((int*)pObj) == 0)
        return (char*)0x007e7860;
    return pObj + 0x370;
}
