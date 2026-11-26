struct MyClass {
    char pad[0xa38];
    int field;
    int setField(int v);
};

int MyClass::setField(int v) {
    field = v;
    return 1;
}

