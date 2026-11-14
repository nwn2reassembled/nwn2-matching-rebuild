class MyClass {
public:
    char pad[62];
    unsigned short data[27];
    int func(unsigned int arg) const;
};

int MyClass::func(unsigned int arg) const {
    unsigned short value;
    if (arg <= 26u)
        value = data[arg];
    else
        value = 0xffff;
    return value != 0xffff;
}
