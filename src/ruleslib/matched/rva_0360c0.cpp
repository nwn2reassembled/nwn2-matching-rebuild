class MyClass {
public:
    bool compare(const void* ptr, unsigned short val) const;
};

bool MyClass::compare(const void* ptr, unsigned short val) const
{
    const unsigned char c = *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(ptr) + 0x15b);
    return val < static_cast<unsigned short>(c);
}

