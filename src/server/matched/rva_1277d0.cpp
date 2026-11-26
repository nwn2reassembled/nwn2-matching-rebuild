class Legacy {
public:
    int dummy;
    int value;
    int setOut(int* out);
};

int Legacy::setOut(int* out) {
    *out = this->value;
    return 1;
}

