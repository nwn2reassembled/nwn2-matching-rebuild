struct Inner {
    char padding[20];
    unsigned char value;
};

struct Outer {
    int dummy1;
    int dummy2;
    int dummy3;
    int dummy4;
    Inner* ptr;

    void setByte(char b);
};

void Outer::setByte(char b) {
    this->ptr->value = static_cast<unsigned char>(b);
}

