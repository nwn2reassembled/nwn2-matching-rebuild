class MyClass {
public:
    int getValue() const;
private:
    char pad[48];
    int value; // at offset 0x30
};

int MyClass::getValue() const { return value; }

