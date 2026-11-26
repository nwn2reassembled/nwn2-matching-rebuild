unsigned char __stdcall LookupByte(const unsigned char* data, unsigned char index)
{
    if (index < 3)
        return data[index + 0x20];

    return -1;
}
