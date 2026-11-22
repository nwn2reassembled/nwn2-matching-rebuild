class MyClass {
public:
    unsigned short getValue();
private:
    unsigned short data;
    virtual void _dummy() {}
};

unsigned short MyClass::getValue() { return data; }

