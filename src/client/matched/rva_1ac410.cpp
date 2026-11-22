class MyClass {
public:
    int getValue();
};

int MyClass::getValue() {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(this) + 0x3F0 );
}

