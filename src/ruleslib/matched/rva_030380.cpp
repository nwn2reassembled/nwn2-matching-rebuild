struct Target { char pad[0x8C]; int value; };

class MyClass {
public:
    static void __stdcall setField(Target* obj, int val);
};

void MyClass::setField(Target* obj, int val) {
    obj->value = val;
}

