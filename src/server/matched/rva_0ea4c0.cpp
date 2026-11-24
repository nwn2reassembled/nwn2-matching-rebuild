struct MyClass {
    MyClass* get_self();
};

MyClass* MyClass::get_self() { return this; }
