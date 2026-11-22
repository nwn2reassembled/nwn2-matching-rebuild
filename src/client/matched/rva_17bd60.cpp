struct MyClass{
    int func(unsigned char idx) const;
};

int MyClass::func(unsigned char idx) const {
    return reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(this)+0xC38)[idx] == 0 ? 1 : 0;
}

