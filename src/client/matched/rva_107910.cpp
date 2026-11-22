struct Inner {
    unsigned int padding[0x7ac18 / 4];
    unsigned int field;
};

struct Outer {
    Inner* inner;
    void setField(unsigned int val);
};

void Outer::setField(unsigned int val) {
    inner->field = val;
}

