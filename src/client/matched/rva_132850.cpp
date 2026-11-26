unsigned long GetField24(const void* obj)
{
    return *(const unsigned long*)((const char*)obj + 0x24);
}
