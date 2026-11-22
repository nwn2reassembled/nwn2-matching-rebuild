struct SomeClass {
    // Pad to reach offset 0x54 (84 decimal)
    char pad1[0x54];
    float f54;
    // Pad between the two floats: 0x84 - 0x54 - sizeof(float) = 44 bytes
    char pad2[44];
    float f84;

    void func(float* out1, float* out2);
};

void SomeClass::func(float* out1, float* out2) {
    *out1 = this->f54;
    *out2 = this->f84;
}

