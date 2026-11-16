class MyClass {
public:
    unsigned char getByte(const void* ptr) const;
};

unsigned char MyClass::getByte(const void* ptr) const
{
    return static_cast<const unsigned char*>(ptr)[8];
}

