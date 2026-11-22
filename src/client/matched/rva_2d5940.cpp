class Legacy {
public:
    char pad[0x1E4];
    float f0;
    float f1;
    float f2;

    void copyFrom(const float* src);
};

void Legacy::copyFrom(const float* src) {
    f0 = src[0];
    f1 = src[1];
    f2 = src[2];
}

