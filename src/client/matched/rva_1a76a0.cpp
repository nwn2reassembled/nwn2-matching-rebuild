class MyClass {
public:
    int* getOffset();
};

int* MyClass::getOffset() {
    return reinterpret_cast<int*>(reinterpret_cast<char*>(this) - 0x730);
}
