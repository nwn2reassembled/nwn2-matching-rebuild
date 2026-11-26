unsigned short GetWordAtOffset4(const void* p)
{
    return *reinterpret_cast<const unsigned short*>(static_cast<const char*>(p) + 4);
}
