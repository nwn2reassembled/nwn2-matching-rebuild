struct C {
    void* vt;
    int f4;
    int f8;
    int fc;
    int f10;
    char f14;
    char pad15[3];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    C* init();
};

C* C::init() {
    vt = (void*)0x7fc250;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f14 = 0;
    f4 = 0;
    f8 = 0;
    fc = 0;
    f10 = 0;
    return this;
}
