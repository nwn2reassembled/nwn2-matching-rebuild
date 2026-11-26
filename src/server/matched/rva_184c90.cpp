struct MyStruct {
    void* getPtr();
};

void* MyStruct::getPtr() {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x2e4);
}

