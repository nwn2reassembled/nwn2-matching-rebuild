struct MyStruct {
    float f[24];
    void process(float*, float*);
};

void MyStruct::process(float* src1, float* src2) {
    // Copy first three floats from the first source.
    f[0] = src1[0];
    f[1] = src1[1];
    f[2] = src1[2];

    // Copy next three floats from the second source.
    f[3] = src2[0];
    f[4] = src2[1];
    f[5] = src2[2];

    // Rearrange into the required offsets.
    f[8]  = f[0];   // offset 0x20
    f[17] = f[3];   // offset 0x44
    f[11] = f[1];   // offset 0x2c
    f[20] = f[4];   // offset 0x50
    f[14] = f[2];   // offset 0x38
    f[23] = f[5];   // offset 0x5c
}

