struct Inner {
    char pad0[0x620];
    double value;
    char pad1[8];
    int zero;
};

struct Outer {
    unsigned short maxValue;
    unsigned short counter;
    Inner* inner;
};

void advance(Outer* p)
{
    unsigned short counter = ++p->counter;
    p->inner->value = (double)counter * *(const double*)0x8146c0 / (double)p->maxValue;
    p->inner->zero = 0;
}
