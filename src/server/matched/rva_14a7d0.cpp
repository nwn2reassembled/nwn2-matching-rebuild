struct MyClass {
    int dummy;
    void* ptr;
    int func() const;
};

int MyClass::func() const {
    return *reinterpret_cast<int*>(static_cast<char*>(ptr) + 0x10058);
}

