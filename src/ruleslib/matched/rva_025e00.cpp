struct MyStruct {
    char pad[0xA8];
    unsigned field;
};

class MyClass {
public:
    static unsigned __stdcall getField(const MyStruct* ptr);
};

unsigned __stdcall MyClass::getField(const MyStruct* ptr) {
    return ptr->field;
}

