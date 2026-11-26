struct Inner {
    int reserved;
    unsigned int code;
};

struct Outer {
    char reserved[0xa];
    unsigned short state;

    int Check(const Inner* p) const;
};

int Outer::Check(const Inner* p) const {
    int result = 0;
    if (state == 3) {
        if (p != 0) {
            if (p->code == 0x3d)
                result = 1;
        }
    }
    return result;
}
