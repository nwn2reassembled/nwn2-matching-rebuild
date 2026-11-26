struct Foo {
    unsigned char pad_0[8];
    unsigned int field_8;
    unsigned short field_C;
};

void Foo_SetTail(Foo *foo, unsigned int value, unsigned short shortValue) {
    foo->field_8 = value;
    foo->field_C = shortValue;
}
