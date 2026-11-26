struct Inner {
    unsigned char pad[0x3a4];
    unsigned char field_3a4;
};

struct Outer {
    int field_0;
    Inner* inner;
    void SetField3a4(unsigned char value);
};

void Outer::SetField3a4(unsigned char value) {
    Inner* p = inner;
    if (p != 0) {
        p->field_3a4 = value;
    }
}
