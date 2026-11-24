struct Legacy {
    char pad[0x48];
    int field;
    void assign(int);
};

void Legacy::assign(int v) {
    this->field = v;
}

