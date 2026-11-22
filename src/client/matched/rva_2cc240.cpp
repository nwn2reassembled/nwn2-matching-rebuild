struct MyStruct {
    int dummy;
    void* ptr;
    int get_value();
};

int MyStruct::get_value() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x158);
}

