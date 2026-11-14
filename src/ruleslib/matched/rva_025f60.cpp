typedef unsigned long DWORD;

struct Legacy {
    static DWORD __stdcall getOffsetValue(void* ptr);
};

DWORD __stdcall Legacy::getOffsetValue(void* ptr)
{
    return *(reinterpret_cast<DWORD*>(reinterpret_cast<char*>(ptr)+0x1cc));
}
