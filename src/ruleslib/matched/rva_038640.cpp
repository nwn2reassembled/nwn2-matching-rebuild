struct MyStruct {
    unsigned char pad[156];
    unsigned int field_9c;
};

class MyClass {
public:
    static unsigned int __stdcall getField(MyStruct *p);
};

unsigned int __stdcall MyClass::getField(MyStruct *p) {
    return p->field_9c;
}

