class MyClass {
public:
    int getValue(void* p);
};

int MyClass::getValue(void* p) {
    return *(int*)((char*)p + 0xEC);
}
