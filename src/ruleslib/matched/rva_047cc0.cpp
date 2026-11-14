struct Legacy {
    int pad[14];
    int fieldA;
    int fieldB;
    int fieldC;
    int fieldD;
    int init();
};

int Legacy::init() {
    fieldA = 0;
    fieldB = 0;
    fieldC = 0;
    fieldD = 0;
    return 1;
}
