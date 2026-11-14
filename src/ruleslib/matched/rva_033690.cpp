struct SomeStruct {
    char pad[36];
    unsigned char field;
};

class MyClass {
public:
    unsigned char getField(const SomeStruct* obj);
};

unsigned char MyClass::getField(const SomeStruct* obj) { return obj->field; }
