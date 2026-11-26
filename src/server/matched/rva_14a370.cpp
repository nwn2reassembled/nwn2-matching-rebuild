struct MyStruct {
    int dummy;          // occupies 0x00-0x03
    void* ptr;          // field at offset +4 (matches [ecx+0x04])
    void setValue(int val);
};

void MyStruct::setValue(int val) {
    *(int*)((char*)ptr + 0x10094) = val;
}
