unsigned char __fastcall CountBytesUntilZero(unsigned char *bytes)
{
    unsigned char i = 0;
    while (i < 0x20)
    {
        if (bytes[i] == 0)
            break;
        i = (unsigned char)(i + 1);
    }
    return i;
}
