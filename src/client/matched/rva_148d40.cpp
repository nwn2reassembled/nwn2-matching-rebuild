class MyClass {
public:
    unsigned int func();
};

unsigned int MyClass::func() {
    unsigned int ptr = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4);
    return *reinterpret_cast<unsigned int*>(ptr + 0x10094);
}

