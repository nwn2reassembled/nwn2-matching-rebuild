unsigned short GetU16Offset4(void* obj)
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(obj) + 4);
}
