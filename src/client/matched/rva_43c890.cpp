class MyClass {
public:
    void setValue(int value);
};

void MyClass::setValue(int value) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x2c) = value;
}

