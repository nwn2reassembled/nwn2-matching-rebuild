class MyClass {
public:
    int setValue(int);
private:
    char pad[0xa38];
    int value;
};

int MyClass::setValue(int val) { value = val; return 1; }
