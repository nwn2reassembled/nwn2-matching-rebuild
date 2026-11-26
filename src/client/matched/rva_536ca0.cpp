struct Inner
{
    char pad0[0x620];
    double value;
    char pad1[0x8];
    int flag;
};

struct Outer
{
    short a;
    short b;
    Inner* inner;
};

void SetOuterValue(Outer* outer, double value)
{
    outer->inner->value = value;
    outer->inner->flag = 0;
    outer->b = 0;
}
