unsigned long GetNetworkId(const void* obj)
{
    return *(const unsigned long*)((const char*)obj + 0x1c);
}
