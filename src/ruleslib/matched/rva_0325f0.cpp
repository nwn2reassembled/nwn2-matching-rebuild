struct MyClass {
    unsigned char pad[60];
    int field;
    static void __stdcall setField(MyClass* target, int value);
};

void MyClass::setField(MyClass* target, int value) {
    target->field = value;
}

