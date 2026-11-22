struct Legacy {
    int a;
    int b;
    int c;
    int d;
    int e; // offset 0x10
    bool foo() const;
};

bool Legacy::foo() const { return e != 0; }
