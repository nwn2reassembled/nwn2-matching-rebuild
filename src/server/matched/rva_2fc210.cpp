void CopyWideString(unsigned short *dest, unsigned short *end, const unsigned short *src)
{
    if (dest == end)
        return;

    unsigned short ch;
    do {
        ch = *src;
        *dest = ch;
        ++dest;
    } while (dest != end);
}
