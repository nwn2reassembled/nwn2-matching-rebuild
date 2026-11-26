class MyClass {
public:
    char* getField();
};

char* MyClass::getField() { return reinterpret_cast<char*>(this) + 0x2F4; }
