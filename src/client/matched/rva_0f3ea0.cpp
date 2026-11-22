class MyClass {
public:
    unsigned int getValue();
private:
    char _pad[412];
    unsigned int value;
};

unsigned int MyClass::getValue()
{
    return value;
}

