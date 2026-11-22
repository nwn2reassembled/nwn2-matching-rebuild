struct MyClass {
    char padding[56];
    void* array_base;
    int getValue(int idx) const;
};

int MyClass::getValue(int idx) const {
    return *reinterpret_cast<int*>(
        reinterpret_cast<char*>(array_base) + idx * 52 + 0x30
    );
}

