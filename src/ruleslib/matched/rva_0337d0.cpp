struct MyStruct {
    char pad[0x718];
    unsigned long field;
};

class MyClass {
public:
    static void __stdcall setField(MyStruct* obj, unsigned long val);
};

void __stdcall MyClass::setField(MyStruct* obj, unsigned long val) {
    obj->field = val;
}

