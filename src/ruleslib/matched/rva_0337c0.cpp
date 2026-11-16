struct MyClass {
    int func(int* ptr);
};

int MyClass::func(int* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x718);
}

