class MyClass {
public:
    static int __stdcall getValue(MyClass* obj);
private:
    char pad[24];
    int value;
};

int MyClass::getValue(MyClass* obj) { return obj->value; }
