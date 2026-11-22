struct S;

class MyClass {
public:
    int dummy;
    short getFieldAtOffset(S* p);
};

short MyClass::getFieldAtOffset(S* p) {
    return *reinterpret_cast<short*>(reinterpret_cast<char*>(p)+0x5c);
}

