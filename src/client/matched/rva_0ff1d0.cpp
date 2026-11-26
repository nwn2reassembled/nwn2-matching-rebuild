struct Inner {
    unsigned char pad0;
    unsigned char flag;
};

struct Outer {
    unsigned char pad[0xb4];
    Inner* inner;

    int IsFlagged();
};

int Outer::IsFlagged() {
    Inner* p = inner;
    if (p != 0 && p->flag != 0)
        return 1;
    return 0;
}
