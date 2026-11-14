struct Other {
    char dummy[48];
    unsigned int value;
};

class MyClass {
public:
    static unsigned int __stdcall getField(const Other* obj);
};

unsigned int __stdcall MyClass::getField(const Other* obj) {
    return obj->value;
}

