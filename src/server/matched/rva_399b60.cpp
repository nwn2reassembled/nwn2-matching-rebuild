class X {
public:
    unsigned int field0;   // offset 0
    unsigned int a1;       // offset 4
    unsigned int a2;       // offset 8
    unsigned int a3;       // offset c
    unsigned int a4;       // offset 10
    unsigned int a5;       // offset 14
    unsigned int a6;       // offset 18
    unsigned int a7;       // offset 1c
    unsigned int a8;       // offset 20
    unsigned int a9;       // offset 24
    unsigned int a10;      // offset 28
    unsigned int a11;      // offset 2c
    short w;               // offset 30
    char b;                // offset 32

    X();
};

X::X() {
    a1 = 0;
    a2 = 0;
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    a8 = 0;
    a9 = 0;
    a10 = 0;
    field0 = 0x814170; // constant written after zeroing fields
    a11 = 0;
    w = 0;
    b = 0;
}

