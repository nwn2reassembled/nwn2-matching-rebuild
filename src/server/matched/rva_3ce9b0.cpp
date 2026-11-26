struct Inner {
    char pad0[0x620];
    double value;
    char pad1[8];
    int flag;
};

struct Outer {
    short first;
    short second;
    Inner* inner;
};

void SetValues(Outer* outer, double value)
{
    outer->inner->value = value;
    outer->inner->flag = 0;
    outer->second = 0;
}
