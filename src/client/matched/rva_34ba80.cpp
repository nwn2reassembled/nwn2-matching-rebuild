struct Src {
    float v0;
    float v1;
    float v2;
};

class MyClass {
public:
    char pad[0x8dc];
    float f1;
    float f2;
    float f3;

    void copyFrom(const Src* src);
};

void MyClass::copyFrom(const Src* src) {
    f1 = src->v0;
    f2 = src->v1;
    f3 = src->v2;
}

