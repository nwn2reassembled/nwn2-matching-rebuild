struct MyStruct {
    unsigned char getByte(void *ptr);
};

unsigned char MyStruct::getByte(void *ptr) {
    return *(unsigned char*)((char*)ptr + 0x178);
}

