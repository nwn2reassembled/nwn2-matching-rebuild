void SetFlag(void* obj, unsigned char value)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(obj) + 0x14) = value;
}
