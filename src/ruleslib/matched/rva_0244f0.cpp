struct Target {
    char pad[12];
    unsigned char lower : 3;
    unsigned char flagBit : 1;
    unsigned char upper : 4;
};

class MyClass {
public:
    static void __stdcall func(Target* p, unsigned int flag);
};

void __stdcall MyClass::func(Target* p, unsigned int flag) {
    p->flagBit = flag != 0;
}
