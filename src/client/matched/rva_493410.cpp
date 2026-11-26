class MyClass {
public:
    unsigned int func();
private:
    char pad1[0xC];          // offset 0x00 – 0x0B
    unsigned int field_c;     // offset 0x0C – 0x0F
    char pad2[8];            // offset 0x10 – 0x17
    unsigned int field_18;   // offset 0x18 – 0x1B
};

unsigned int MyClass::func() {
    return this->field_18 + this->field_c + 1;
}

