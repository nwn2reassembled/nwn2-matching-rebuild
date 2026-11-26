struct Legacy {
    char pad0[12];
    short fieldC;
    char padE[2];
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    char pad2C[4];
    unsigned char flag30;
    char pad34[3];
    int field34;

    int init();
};

int Legacy::init() {
    field14 = 0;
    field18 = 0;
    field34 = 0;
    fieldC = 0;
    field10 = 0;
    field1C = 0;
    field20 = 0;
    field24 = 0;
    field28 = 0;
    flag30 = 5;
    return 1;
}

