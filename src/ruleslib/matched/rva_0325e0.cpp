class MyClass {
public:
    int getField(void* p);
};

int MyClass::getField(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x1C);
}

