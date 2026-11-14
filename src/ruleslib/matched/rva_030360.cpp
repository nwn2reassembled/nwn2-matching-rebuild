struct MyObject { char pad[0x88]; unsigned int field; };

class MyClass {
public:
    void setField(MyObject* obj, unsigned int value);
};

void MyClass::setField(MyObject* obj, unsigned int value) {
    obj->field = value;
}

