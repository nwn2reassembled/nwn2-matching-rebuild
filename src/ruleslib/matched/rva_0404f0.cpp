struct ParamStruct {
    char pad[8];
    unsigned int value;
};

struct OtherStruct {
    char pad[0x34];
    unsigned int limit;
};

class MyClass {
public:
    unsigned int compute(ParamStruct* p, unsigned int* out);
private:
    char pad1[0x50];
    OtherStruct* ptr;
    char pad2[0x2c];
    unsigned int base;
};

unsigned int MyClass::compute(ParamStruct* p, unsigned int* out) {
    if (p && base) {
        unsigned int val = p->value;
        unsigned int limit = ptr->limit;
        if (val < limit) {
            *out = limit - val;
            return p->value + base;
        }
    }
    return 0;
}
