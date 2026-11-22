class MyClass {
public:
    unsigned char func(void* p);
};

unsigned char MyClass::func(void* p) {
    unsigned char* q = static_cast<unsigned char*>(p);
    return q[0x15];
}

