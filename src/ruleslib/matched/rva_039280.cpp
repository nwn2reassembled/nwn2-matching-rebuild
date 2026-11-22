class MyClass {
public:
    unsigned int getValueFrom(void* ptr);
};

unsigned int MyClass::getValueFrom(void* ptr) {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(ptr) + 0x70);
}

