struct LegacyClass {
    char padding[0x27C];
    float field_27c;
    float field_280;
    float field_284;

    void copy(const float* src);
};

void LegacyClass::copy(const float* src) {
    field_27c = src[0];
    field_280 = src[1];
    field_284 = src[2];
}

