void __stdcall CopyHandle(unsigned int* dest, const unsigned int* src)
{
    if (dest != 0)
    {
        *dest = *src;
    }
}
