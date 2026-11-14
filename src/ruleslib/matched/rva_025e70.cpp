struct MyStruct {
    char pad[0xb4];
    unsigned int field;
};
class MyClass {
public:
    static unsigned int __stdcall GetField(MyStruct* p);
};
unsigned int __stdcall MyClass::GetField(MyStruct* p) { return p->field; }
