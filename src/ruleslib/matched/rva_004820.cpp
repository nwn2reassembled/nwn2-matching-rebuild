struct MyClass {
    int field0;
    int field4;
    int foo(int);
};

int MyClass::foo(int arg) {
    if (field4 == 0 || arg < 0 || arg >= field0)
        return 0;
    return arg * 0xf4 + field4;
}

