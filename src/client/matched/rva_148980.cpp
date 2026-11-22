struct MyClass {
    int method();
};

int MyClass::method() {
    char* base = reinterpret_cast<char*>(this);
    int* ptr = *reinterpret_cast<int**>(base + 4);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x100c8);
}

