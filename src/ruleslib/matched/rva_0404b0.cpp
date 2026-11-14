struct Arg1 {
    int dummy[2];
    unsigned int field8;
};

struct Inner {
    char pad[36];
    unsigned int value;
};

class LegacyClass {
public:
    unsigned int compute(Arg1* a, unsigned int* out);
private:
    char pad0[0x50];
    Inner* ptr50;
    char pad54[0x18];
    unsigned int offset6c;
};

unsigned int LegacyClass::compute(Arg1* a, unsigned int* out) {
    if (a && offset6c) {
        unsigned int offset = a->field8;
        unsigned int val = ptr50->value;
        if (offset < val) {
            *out = val - offset;
            return a->field8 + offset6c;
        }
    }
    return 0;
}
