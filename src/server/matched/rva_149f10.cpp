struct MyClass {
    int dummy;
    void* field;
    int func();
};

int MyClass::func() {
    return *(int*)((char*)field + 0x100b8);
}

