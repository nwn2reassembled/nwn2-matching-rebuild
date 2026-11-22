struct Arg {
    char pad[0x64];
    float value;
};

class Legacy {
public:
    int dummy;
    float getFloat(Arg* p) const;
};

float Legacy::getFloat(Arg* p) const {
    return p->value;
}

