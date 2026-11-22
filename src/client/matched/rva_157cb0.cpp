struct MyStruct {
    char* foo();
};

char* MyStruct::foo() { return reinterpret_cast<char*>(this) - 0xad0; }
