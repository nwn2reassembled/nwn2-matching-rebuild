struct Target { char pad[0x100fc]; int field; };

class MyClass {
public:
    int dummy;
    Target* ptr;
    void setField(int value);
};

void MyClass::setField(int value) { ptr->field = value; }
