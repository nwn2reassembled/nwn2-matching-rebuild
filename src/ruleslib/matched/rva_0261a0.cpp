struct MyStruct {
    static int __stdcall getValue(void* p);
};

int MyStruct::getValue(void* p) {
    return *reinterpret_cast<int*>(static_cast<char*>(p)+0x1a8);
}

