struct MyStruct {
    unsigned char foo(void* p);
};

unsigned char MyStruct::foo(void* p) {
    return *(unsigned char*)((char*)p + 0x38);
}

