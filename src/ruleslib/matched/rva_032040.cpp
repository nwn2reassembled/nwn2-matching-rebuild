struct Param {
    char pad[94];
    unsigned short field;
};

class MyClass {
public:
    static unsigned short __stdcall getField(Param* p);
};

unsigned short __stdcall MyClass::getField(Param* p) {
    return p->field;
}

