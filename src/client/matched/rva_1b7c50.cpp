class MyClass {
public:
    void setValue(unsigned short);
private:
    char padding[872];   // 0x368 bytes of padding before the field
    unsigned short value; // stored at offset 0x368
};

void MyClass::setValue(unsigned short a) {
    value = a;
}

