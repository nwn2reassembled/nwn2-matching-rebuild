bool IsFlagSet(void* obj)
{
    unsigned char b = *(unsigned char*)((char*)obj + 0x15);
    return (unsigned char)(b & 2) == 2;
}
