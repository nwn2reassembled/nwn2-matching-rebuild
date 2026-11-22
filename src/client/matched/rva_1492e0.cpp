struct OffStruct { char pad[0x10194]; int field; };

class MyClass {
public:
    int dummy;
    void* ptr;
    int foo();
};

int MyClass::foo() {
    return reinterpret_cast<OffStruct*>(ptr)->field;
}

