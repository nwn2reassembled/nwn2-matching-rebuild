struct Legacy {
    int _pad[10];
    int field28;
    int field2c;
    int field30;
    int field34;
    void setValues(int a1, int a2);
};

void Legacy::setValues(int a1, int b) {
    field28 = a1;
    field2c = b;
    field30 = 0x989680; // 1000000 decimal
    field34 = 0;
}

