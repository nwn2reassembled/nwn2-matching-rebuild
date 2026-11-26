struct Inner {
    unsigned int field_00[5];
    unsigned int field_14;
};

struct Outer {
    unsigned char pad_00[0x23];
    char innerPtrBytes[4];
};

unsigned int __cdecl GetInnerField14(Outer* outer)
{
    Inner* inner = *(Inner**)(void*)outer->innerPtrBytes;
    return inner->field_14;
}
