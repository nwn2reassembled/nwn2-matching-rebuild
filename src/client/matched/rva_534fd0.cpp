struct S
{
    char pad_00[0x14];
    int field_14;
    char pad_18[0x1c];
    char* field_34;
    char pad_38[0x0e];
    short field_46;
    char pad_48[0x08];
    short field_50;
    char pad_52[0x09];
    unsigned char field_5b;
};

void __cdecl f(S* p)
{
    int n = p->field_46;
    p->field_14 = n;
    p->field_34 = (char*)p + n * p->field_5b + p->field_50 + 0x5c;
}
