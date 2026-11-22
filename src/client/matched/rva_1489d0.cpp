class MyClass {
public:
    int field;
    virtual int getValue() const;
};

int MyClass::getValue() const
{
    return field + 0x100d4;
}

