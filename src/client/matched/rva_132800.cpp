int __cdecl IsFlagSet(const void* p)
{
    return (*(const char*)((const char*)p + 0x15) & 1) == 1;
}
