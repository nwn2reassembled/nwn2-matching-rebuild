class MyClass {
public:
    unsigned long getField();
private:
    char _pad1[24];
    unsigned long field_at_0x18;
};

unsigned long MyClass::getField() { return this->field_at_0x18; }
