struct Arg {
    char padding[4];
    unsigned int value;
};

class MyClass {
public:
    int method(const Arg* arg);
private:
    char pad0[10];
    short field_10;
};

int MyClass::method(const Arg* arg) {
    int result = 0;
    if (field_10 == 3 && arg && arg->value == 61)
        result = 1;
    return result;
}
