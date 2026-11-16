struct MyStruct {
    char padding[84];                 // offset 0x54 to the DWORD field
    unsigned long value;              // field at offset 0x54
    static unsigned long __stdcall getField(MyStruct* p);
};

unsigned long MyStruct::getField(MyStruct* p) {
    return p->value;
}
