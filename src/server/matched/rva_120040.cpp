struct Legacy {
    int dummy0;
    int dummy1;
    int field_8;
    int field_c;
    int field_10;
    int field_14;

    void initialize(int, int);
};

void Legacy::initialize(int a, int b) {
    this->field_10 = a;
    this->field_14 = b;
    this->field_8 = *reinterpret_cast<int const*>(0x083E06C);
    this->field_c = 0;
}

