struct Inner {
    char pad[0x88];
    unsigned int field;
};

struct MyClass {
    int dummy;          // occupies offset 0-3
    Inner* ptr;         // stored at offset 4, matches [ecx+0x4]
    unsigned int getValue();
};

unsigned int MyClass::getValue() {
    return ptr->field;   // loads [ptr+0x88] and returns it
}
