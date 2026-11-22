class MyClass {
public:
    unsigned short getField() const;
    int dummy;
};

unsigned short MyClass::getField() const {
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 0x10470);
}

