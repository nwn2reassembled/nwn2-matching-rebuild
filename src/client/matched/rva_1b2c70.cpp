class MyClass {
public:
    int getField();
private:
    char pad[0x4b4];
    int field;
};
int MyClass::getField() { return field; }
