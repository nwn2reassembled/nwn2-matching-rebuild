struct Target {
    char pad[0x32c];
    unsigned int field;
};

class Legacy {
public:
    void setZero(Target* p);
};

void Legacy::setZero(Target* p) { p->field = 0; }
