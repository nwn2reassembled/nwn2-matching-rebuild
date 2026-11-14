
class MyClass {
public:
    unsigned short getByteC0(void* ptr);
};

unsigned short MyClass::getByteC0(void* ptr) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0xc0);
}

