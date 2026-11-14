struct MyStruct {
    unsigned char data[64];
};

class Foo {
public:
    static void __stdcall setByte(MyStruct* obj, unsigned char val);
};

void Foo::setByte(MyStruct* obj, unsigned char val) {
    obj->data[42] = val;
}

