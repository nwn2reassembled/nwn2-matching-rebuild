unsigned short __cdecl LoadSwapped16(const unsigned char* p)
{
    unsigned char b1 = p[1];
    unsigned char b0 = p[0];

    unsigned char tmp[2];
    tmp[0] = b1;
    tmp[1] = b0;

    unsigned short w = *reinterpret_cast<const unsigned short*>(tmp);

    return w;
}
