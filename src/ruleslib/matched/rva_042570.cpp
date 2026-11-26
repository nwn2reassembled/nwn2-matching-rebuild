typedef unsigned short WORD;
typedef unsigned long DWORD;

WORD __stdcall RulesCheckFlag(DWORD dwFlags)
{
    WORD wResult = 0;

    if ((dwFlags & 0xFFFF0000UL) != 0)
    {
        wResult = 0;
    }

    return wResult;
}
