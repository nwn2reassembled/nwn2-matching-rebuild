struct LegacyObject {
    unsigned int getValue() const;
};

unsigned int LegacyObject::getValue() const
{
    unsigned char idx = *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 0x36A);
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x320 + static_cast<unsigned int>(idx)*4);
}
