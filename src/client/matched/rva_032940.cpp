struct MyStruct {
    char pad[88];
    int field;
    int* getFieldPtr();
};

int* MyStruct::getFieldPtr() { return reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x58); }
