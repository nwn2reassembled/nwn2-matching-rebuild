struct MyClass {
    int getValue();
};

int MyClass::getValue() {
    char* p = *reinterpret_cast<char**>(reinterpret_cast<char*>(this)+4);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x100b4);
}

