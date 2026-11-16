struct SomeStruct;

class MyClass {
public:
    unsigned char func(SomeStruct* p);
};

unsigned char MyClass::func(SomeStruct* p) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p)+0x190);
}

