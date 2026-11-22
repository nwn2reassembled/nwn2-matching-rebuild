struct LegacyClass {
    unsigned char getByte(const void* ptr) const;
};

unsigned char LegacyClass::getByte(const void* ptr) const
{
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(ptr)+0x56);
}
