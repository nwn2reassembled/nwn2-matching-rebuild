class MyClass {
public:
    unsigned int getField(const void* ptr) const;
};

unsigned int MyClass::getField(const void* ptr) const {
    return *(const unsigned int*)((const char*)ptr + 0xa4);
}
