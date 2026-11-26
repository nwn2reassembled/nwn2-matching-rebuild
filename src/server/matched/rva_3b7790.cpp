void StoreWordAtOffset(void* object, unsigned short value)
{
    *(unsigned short*)((char*)object + 0x163) = value;
}
