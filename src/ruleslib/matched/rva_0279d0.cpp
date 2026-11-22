struct MyClass {
    int method(int, int);
};

int MyClass::method(int a, int b) { return (b << 5) + a + 0x62; }
