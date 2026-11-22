class MyClass {
public:
    int getField() const;
private:
    int pad[49];
    int value;
};
int MyClass::getField() const { return value; }

