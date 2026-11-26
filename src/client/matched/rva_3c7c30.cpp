class MyClass {
public:
    unsigned char getByte() const;
};

unsigned char MyClass::getByte() const
{
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 0x87c);
}

