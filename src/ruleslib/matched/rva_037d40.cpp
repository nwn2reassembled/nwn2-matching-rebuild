struct MyClass {
    void method(void* ptr, float f);
};

void MyClass::method(void* ptr, float f) {
    *(float*)((char*)ptr + 0x64) = f;
}

