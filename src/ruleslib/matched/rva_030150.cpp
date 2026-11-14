class MyClass {
public:
    static int __stdcall getField(MyClass* p);
};

int MyClass::getField(MyClass* p) { return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x88); }
