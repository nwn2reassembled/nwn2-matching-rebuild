struct MyStruct {
    char pad[1540];
    int field604;
};

class MyClass {
public:
    static void __stdcall setField(MyStruct* obj, int val);
};

void MyClass::setField(MyStruct* obj, int val) {
    obj->field604 = val;
}

