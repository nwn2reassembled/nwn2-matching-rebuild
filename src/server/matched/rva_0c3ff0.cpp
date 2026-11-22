struct MyClass {
    int getField();
private:
    char padding[0xCC];
    int field;
};

int MyClass::getField()
{
    return field;
}

