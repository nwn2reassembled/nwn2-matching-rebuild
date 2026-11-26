struct MyClass {
    char pad[60];
    unsigned char value;

    unsigned char getByte();
};

unsigned char MyClass::getByte() { return value; }

