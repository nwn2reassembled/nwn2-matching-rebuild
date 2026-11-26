struct Inner {
    char reserved[0x24];
    int value;
};

class Outer {
public:
    int GetValue();
private:
    char reserved[0x9b4];
    Inner* inner;
};

int Outer::GetValue() {
    if (inner)
        return inner->value;
    return 0;
}
