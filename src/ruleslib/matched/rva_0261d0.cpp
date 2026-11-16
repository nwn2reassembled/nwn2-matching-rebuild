class MyClass {
public:
    unsigned long getField(void* ptr);
};

unsigned long MyClass::getField(void* ptr) {
    return *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(ptr)+0x1B4);
}
