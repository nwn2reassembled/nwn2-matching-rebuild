struct MyClass {
    unsigned char func(const void* p);
};

unsigned char MyClass::func(const void* p)
{
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(p)+0x27);
}

