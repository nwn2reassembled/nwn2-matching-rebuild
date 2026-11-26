unsigned char ReadFlagByte(void* p)
{
    return *(unsigned char*)(static_cast<char*>(p) + 0x15);
}
