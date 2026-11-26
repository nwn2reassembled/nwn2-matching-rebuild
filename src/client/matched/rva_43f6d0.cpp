struct Legacy {
    int a;
    int b;
    int c;
    int d;
    int get() const;
};

int Legacy::get() const { return d + 0x7c; }

