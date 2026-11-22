class MyClass {
public:
    short getField(void* ptr);
};

short MyClass::getField(void* ptr) {
    return *reinterpret_cast<short*>(static_cast<char*>(ptr) + 0x2C);
}

