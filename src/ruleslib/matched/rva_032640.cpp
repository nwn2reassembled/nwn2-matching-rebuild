class MyClass {
public:
    int ordinary;
    static int __stdcall func(MyClass* ptr, unsigned idx);
};

int MyClass::func(MyClass* ptr, unsigned idx) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x30 + idx*4);
}

