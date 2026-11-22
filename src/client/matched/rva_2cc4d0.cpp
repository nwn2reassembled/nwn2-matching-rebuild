struct MyStruct {
    unsigned int dummy;
    unsigned int* ptr;
    void foo();
};

void MyStruct::foo() {
    *(unsigned int*)((char*)ptr + 0x2c) = 0;
}

