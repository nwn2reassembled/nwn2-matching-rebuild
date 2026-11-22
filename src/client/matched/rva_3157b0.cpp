class MyClass {
public:
    int get_value(unsigned int idx);
};

int MyClass::get_value(unsigned int idx) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x464 + (idx << 4));
}

