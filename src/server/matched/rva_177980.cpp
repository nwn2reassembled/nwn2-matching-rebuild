class MyClass {
public:
    MyClass* get_this();
};

MyClass* MyClass::get_this() { return this; }
