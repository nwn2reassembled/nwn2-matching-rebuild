class MyClass {
public:
    unsigned char scan();
};

unsigned char MyClass::scan() {
    const unsigned char* ptr = reinterpret_cast<const unsigned char*>(this);
    unsigned char i = 0;
    do {
        if (!ptr[i])
            break;
        ++i;
    } while (i < 32);
    return i;
}
