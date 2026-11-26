struct Inner {
    unsigned char pad0[4];
    void* field_04; // offset 0x04
};

struct Outer {
    unsigned char pad[0x09B4];
    Inner* inner; // +0x09B4
};

void* __fastcall GetInnerField_356eb0(Outer* pthis)
{
    Inner* p = pthis->inner;
    return p ? p->field_04 : 0;
}
