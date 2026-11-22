struct MyStruct {
    int member;
    void* getOffset();
};

void* MyStruct::getOffset() { return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x30); }
