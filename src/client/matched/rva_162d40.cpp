struct MyClass {
    char pad[0x2f4];
    char* getPad();
};

char* MyClass::getPad() {
    return reinterpret_cast<char*>(this) + 0x2f4;
}
