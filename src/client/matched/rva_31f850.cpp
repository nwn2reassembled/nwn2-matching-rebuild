struct Source {
    float a;
    float b;
    float c;
};

struct Legacy {
    char pad0[272];
    float f110;
    float f114;
    float f118;
    char pad1[12];
    float f128;
    float f12c;
    float f130;
    char pad2[128];
    float f1b4;
    float f1b8;
    float f1bc;

    void copyFrom(const Source* src);
};

void Legacy::copyFrom(const Source* src) {
    f110 = src->a;
    f114 = src->b;
    f118 = src->c;
    f128 = f1b4;
    f12c = f1b8;
    f130 = f1bc;
}

