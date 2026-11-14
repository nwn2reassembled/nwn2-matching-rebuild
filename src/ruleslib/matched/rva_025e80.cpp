class MyClass {
public:
    int getValue(const void* p);
};

int MyClass::getValue(const void* p) {
    return *(int*)((char*)p + 0xCC);
}

