struct MyOther;
class MyClass {
public:
    static int __stdcall getValue(MyOther *ptr);
};
struct MyOther { char padding[0x58]; int value; };
int MyClass::getValue(MyOther* ptr) { return ptr->value; }

