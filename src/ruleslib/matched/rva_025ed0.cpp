struct Other {
    char pad[0xE4];
    int value;
};

class X {
public:
    int getField(Other* p) const;
};

int X::getField(Other* p) const {
    return p->value;
}
