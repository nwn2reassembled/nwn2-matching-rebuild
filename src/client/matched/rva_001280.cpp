class MyClass {
public:
    int value;
    int getValue();
};

int MyClass::getValue() {
    return *reinterpret_cast<int const*>(this);
}

