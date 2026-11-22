struct LegacyObj {
    char pad[0x1DC];
    float field1;
    float field2;
    float field3;

    void copyFrom(const float* src);
};

void LegacyObj::copyFrom(const float* src) {
    field1 = src[0];
    field2 = src[1];
    field3 = src[2];
}

