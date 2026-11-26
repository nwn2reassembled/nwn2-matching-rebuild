struct Legacy {
    char pad0[384];
    int field_180;
    char pad1[3192];
    float field_dfC;
    int field_e00;
    void func();
};

void Legacy::func() {
    this->field_dfC = 1.0f;
    this->field_180 = this->field_e00;
}

