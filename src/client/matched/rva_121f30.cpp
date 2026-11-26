typedef int BOOL;

typedef unsigned long DWORD;

BOOL __stdcall TryReleaseHandle(DWORD* pOut)
{
    if (pOut == 0)
        return 0;

    *pOut = 0;
    return 1;
}
