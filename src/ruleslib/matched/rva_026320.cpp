class MyClass {
public:
    static int __stdcall getValue(void *p);
};

int MyClass::getValue(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x1fc);
}

