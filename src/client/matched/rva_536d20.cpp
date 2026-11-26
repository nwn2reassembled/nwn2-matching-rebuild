struct Inner {
    char pad0[0x61e];
    unsigned short field_61e;
    double field_620;
};

struct Outer {
    char pad0[4];
    Inner* inner;
};

void SetInnerDefaults(Outer* outer)
{
    outer->inner->field_620 = 1.0;
    outer->inner->field_61e = 0;
}
