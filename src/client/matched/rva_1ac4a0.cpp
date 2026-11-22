class MyClass {
public:
    int dummy;                     // ordinary member
    int* getFieldPtr();
};

int* MyClass::getFieldPtr() {
    return reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x414);
}

