class MyClass {
public:
    int getField(void* p);
};

int MyClass::getField(void* p) { return *(int*)((char*)p + 0x60C); }
