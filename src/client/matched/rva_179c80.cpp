struct MyClass {
    char* getOffset(int);
};

char* MyClass::getOffset(int index) {
    return reinterpret_cast<char*>(this) + (index * 8) + 0x48;
}

