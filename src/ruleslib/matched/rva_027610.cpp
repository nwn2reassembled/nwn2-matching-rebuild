struct TargetStruct { unsigned char pad[20]; unsigned int field; };

class MyClass {
public:
    static void __stdcall setField(TargetStruct* obj, unsigned int value);
};

void __stdcall MyClass::setField(TargetStruct* obj, unsigned int value) {
    obj->field = value;
}

