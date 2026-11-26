void SetField24(void* obj, int value)
{
    *reinterpret_cast<int*>(static_cast<char*>(obj) + 0x24) = value;
}
