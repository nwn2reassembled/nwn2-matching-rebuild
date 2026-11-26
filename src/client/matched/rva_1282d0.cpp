struct Inner {
    unsigned char pad_00[0xc];
    int value; // +0xc
};

struct Outer {
    unsigned char pad_00[0x10];
    Inner* inner; // +0x10

    int GetValue();
};

int Outer::GetValue() {
    Inner* p = this->inner;
    if (p != 0) {
        return p->value;
    }
    return 0;
}
