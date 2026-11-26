struct Legacy {
    char pad[0x31c];
    int value;
    void setValue(int);
};

void Legacy::setValue(int v) {
    value = v;
}

