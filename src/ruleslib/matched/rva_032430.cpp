struct MyStruct {
    char padding[36];
    int field;
};

class Foo {
public:
    static void __stdcall setField(MyStruct* obj, int val);
};

void Foo::setField(MyStruct* obj, int val) {
    obj->field = val;
}

