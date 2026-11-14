class MyClass {
public:
    unsigned char padding[0x68];
    unsigned short valueAt68;
    static void __stdcall setValue(MyClass* obj, unsigned short val);
};

void MyClass::setValue(MyClass* obj, unsigned short val) {
    obj->valueAt68 = val;
}

