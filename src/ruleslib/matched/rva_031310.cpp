class Target {
public:
    char pad[0x5b0];
    unsigned int field;
};

struct Dummy {
    void setField(Target* t, unsigned int v);
};

void Dummy::setField(Target* t, unsigned int v) {
    t->field = v;
}

