struct Target {
    unsigned char pad[12];
    unsigned char lower : 1;
    unsigned char flag : 1;
    unsigned char upper : 6;
};

struct MyClass {
    static void __stdcall func(void* ptr, int flag);
};

void __stdcall MyClass::func(void* ptr, int flag) {
    ((Target*)ptr)->flag = flag != 0;
}
