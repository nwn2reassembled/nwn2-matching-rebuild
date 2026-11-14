struct MyStruct;

class MyClass {
public:
    float getValue(MyStruct* p);
};

struct MyStruct {
    char padding[0x38];
    float value;
};

float MyClass::getValue(MyStruct* p) {
    return p->value;
}

