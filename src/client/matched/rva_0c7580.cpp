struct Inner {
    unsigned char pad[0xC4];
    int field; // offset 0xC4
};

struct Outer {
    Inner* inner; // offset 0x00
    int GetNestedValue();
};

int Outer::GetNestedValue() {
    if (inner != 0)
        return inner->field;
    return 0;
}
