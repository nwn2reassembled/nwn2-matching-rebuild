struct Inner {
    unsigned char pad[0x7ac40];
    unsigned short field_7ac40;
};

class Outer {
public:
    void SetWordAtOffset(unsigned short value);
private:
    Inner* inner_;
};

void Outer::SetWordAtOffset(unsigned short value) {
    Inner* inner = inner_;
    if (inner != 0) {
        inner->field_7ac40 = value;
    }
}
