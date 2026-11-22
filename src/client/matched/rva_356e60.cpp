struct MyClass {
    char padding[0x9a0];
    unsigned int value;
    unsigned int getValuePlusOffset() const;
};

unsigned int MyClass::getValuePlusOffset() const
{
    return value + 0xcc;
}

