struct MyClass {
    int dummy;
    void* ptr;
    int func() const;
};

int MyClass::func() const {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x10090);
}

