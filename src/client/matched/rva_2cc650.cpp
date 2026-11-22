struct Inner {
    virtual ~Inner() {}
    int value;
};

struct Outer {
    virtual ~Outer() {}
    Inner* inner;
    int getValue();
};

int Outer::getValue() {
    return inner->value;
}

