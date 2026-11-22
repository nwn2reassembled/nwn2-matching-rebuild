struct MyStruct {
    unsigned char getByte();
};

unsigned char MyStruct::getByte() { return *(unsigned char*)((char*)this + 0x20); }
