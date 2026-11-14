struct MyStruct {
    char pad[0x18];
    unsigned int value;
};

class MyClass {
public:
    static void __stdcall foo(MyStruct* obj, unsigned int value);
};

void MyClass::foo(MyStruct* obj, unsigned int value) {
    obj->value = value;
}

