struct Inner;
class Outer {
public:
    const Inner* p;
    short getValue() const;
};
struct Inner {
    unsigned char pad[0x48];
    short value;
};
short Outer::getValue() const { return p->value; }
