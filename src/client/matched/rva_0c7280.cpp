struct Inner {
    int other;
    int value;
};

struct Outer {
    int other;
    Inner* inner;
    int GetInnerValue() const;
};

int Outer::GetInnerValue() const {
    if (inner != 0) {
        return inner->value;
    }
    return 0;
}
