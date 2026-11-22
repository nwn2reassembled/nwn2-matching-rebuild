struct Legacy {
    char pad0[0x54];
    float f1;
    char pad1[36];
    float f2;
    char pad2[4];
    float f3;

    void copy(float*, float*, float*);
};

void Legacy::copy(float* a, float* b, float* c)
{
    *a = f1;
    *b = f2;
    *c = f3;
}

