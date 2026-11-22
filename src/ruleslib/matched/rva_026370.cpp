
struct MyStruct {
    char padding[0x20c]; // offset 0x20c
    int value;
};

class MyClass {
public:
    static int __stdcall getValue(MyStruct* p);
};

int MyClass::getValue(MyStruct* p) { return p->value; }

