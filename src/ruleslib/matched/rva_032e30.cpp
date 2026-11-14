struct MyStruct {
    int getField(void* ptr);
};

int MyStruct::getField(void* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x14);
}
