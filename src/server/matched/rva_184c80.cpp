struct MyStruct {
    char* getOffset();
};

char* MyStruct::getOffset() {
    return reinterpret_cast<char*>(this) + 0x2D4;
}

