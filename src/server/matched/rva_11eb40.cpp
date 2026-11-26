class MyClass {
public:
    int getValue();
private:
    char pad[24]; // offset 0x18
    int value;
};

int MyClass::getValue() { return value; }
