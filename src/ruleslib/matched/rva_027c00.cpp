class MyClass {
public:
    int getValue(int);
};

int MyClass::getValue(int p) { return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x30c); }
