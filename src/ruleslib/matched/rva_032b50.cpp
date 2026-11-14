struct MyStruct {
    char pad[0x48];        // padding to reach offset 0x48
    unsigned short field_48;   // target member
};

class C {
public:
    static void __stdcall setField(MyStruct* p, unsigned short val);
};

void C::setField(MyStruct* p, unsigned short val) {
    p->field_48 = val;
}

