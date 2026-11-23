struct Child {
    char padding[0x58];
    int value;
};

struct Legacy {
    int unused;
    Child* child;
    int read() const;
};

int Legacy::read() const {
    return child->value;
}
