struct MyStruct {
    void* dummy;
    void* ptr;
    int getValue() const;
};

int MyStruct::getValue() const {
    return *reinterpret_cast<int*>(static_cast<char*>(ptr) + 0x10078);
}

