class MyClass {
public:
    void setValue(unsigned int value);
private:
    struct Target { unsigned char pad[0x1000c]; unsigned int field; };
    Target* ptr;
    virtual void dummy() {}
};

void MyClass::setValue(unsigned int value) {
    ptr->field = value;
}

