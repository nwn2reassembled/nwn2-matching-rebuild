class Legacy {
public:
    unsigned char getByte(const void* ptr) const;
};

unsigned char Legacy::getByte(const void* ptr) const
{
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(ptr) + 0x40);
}
