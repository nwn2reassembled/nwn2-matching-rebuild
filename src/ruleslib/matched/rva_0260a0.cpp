struct MyClass {
    int getValue(int* ptr);
};

int MyClass::getValue(int* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x128);
}
