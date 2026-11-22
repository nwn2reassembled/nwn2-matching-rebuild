struct MyStruct {
    int placeholder;
    void* ptr_member;
    unsigned int getValue();
};

unsigned int MyStruct::getValue() {
    return *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(ptr_member) + 0x100fc );
}

