unsigned char __stdcall GetByteAt(void* table, unsigned char index)
{
    if (index <= 1)
        return index;
    if (index > 0x14)
        return index;
    unsigned char* bytes = (unsigned char*)table;
    return bytes[index + 0x5c4];
}
