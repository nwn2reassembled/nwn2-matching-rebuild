struct Other {
    char pad[0x82];
    unsigned short value;
};

struct MyClass {
    Other* ptr;
    unsigned short getValue() const;
};

unsigned short MyClass::getValue() const {
    return static_cast<unsigned short>(ptr->value);
}

