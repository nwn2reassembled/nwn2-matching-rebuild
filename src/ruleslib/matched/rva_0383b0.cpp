struct MyClass {
    unsigned short getField(const void* p) const;
};

unsigned short MyClass::getField(const void* p) const
{
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(p)+0x78);
}

