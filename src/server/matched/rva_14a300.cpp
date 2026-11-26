struct MyClass {
    int dummy;
    void* ptr;
    int getValue();
};

int MyClass::getValue() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x10020);
}

