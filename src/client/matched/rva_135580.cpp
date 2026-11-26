struct CEngine
{
    char pad[0x1BB8];
    int refCount;
};

int __cdecl AddRefEngine(CEngine *pEngine)
{
    int old = pEngine->refCount;
    int next = old + 1;
    pEngine->refCount = next;
    if (next < 0)
        pEngine->refCount = 0;
    return old;
}
