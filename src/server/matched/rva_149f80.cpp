struct Inner {
    unsigned char data[0x100c8];
    unsigned int field;
};

struct Outer {
    int dummy;
    Inner* innerPtr;
    void setByte(unsigned char v);
};

void Outer::setByte(unsigned char v) {
    innerPtr->field = v;
}

