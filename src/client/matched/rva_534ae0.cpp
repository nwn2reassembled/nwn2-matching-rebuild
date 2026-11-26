unsigned long __cdecl ReverseBytes(const void *p)
{
    const unsigned char *src = (const unsigned char *)p;
    unsigned long result;
    unsigned char *dst = (unsigned char *)&result;

    dst[0] = src[3];
    dst[1] = src[2];
    dst[2] = src[1];
    dst[3] = src[0];

    return result;
}
