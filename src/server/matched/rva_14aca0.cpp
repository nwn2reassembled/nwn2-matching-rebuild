struct Obj {
    int dummy[6];          // bytes 0x00..0x17
    int field_18;           // byte offset 0x18
};

class MyClass {
public:
    int getField();
};

int MyClass::getField() {
    Obj* p = *reinterpret_cast<Obj**>(0x86442c);
    return p->field_18;
}

