struct Src { float a; float b; float c; };

struct MyStruct {
    char pad[0x1d8];
    float f1;
    float f2;
    float f3;
    float g1;
    float g2;
    float g3;
    void copyFrom(const Src* src);
};

void MyStruct::copyFrom(const Src* src) {
    f1 = src->a;
    f2 = src->b;
    f3 = src->c;
    g1 = src->a;
    g2 = src->b;
    g3 = src->c;
}

