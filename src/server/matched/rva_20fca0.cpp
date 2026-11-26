class MyClass {
public:
    int setValue(float val);
private:
    char pad[0xA3C];
    float stored;
};

int MyClass::setValue(float val) {
    this->stored = val;
    return 1;
}

