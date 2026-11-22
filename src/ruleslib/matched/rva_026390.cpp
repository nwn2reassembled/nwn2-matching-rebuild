class Legacy {
public:
    int getField(const struct Target* p);
};

struct Target {
    char pad[0x214];
    int value;
};

int Legacy::getField(const Target* p) { return p->value; }
