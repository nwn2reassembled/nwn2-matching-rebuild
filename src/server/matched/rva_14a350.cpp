struct Inner {
    char padding[0x10074];
    unsigned int value;
};

struct Outer {
    unsigned int dummy; // offset 0
    Inner* ptr;         // offset 4

    unsigned int getValue();
};

unsigned int Outer::getValue() {
    return this->ptr->value;
}

