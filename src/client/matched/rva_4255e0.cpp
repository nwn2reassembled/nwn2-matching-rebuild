struct Source { float a; float b; float c; };

class Target {
public:
    void copyFrom(const Source* src);
private:
    char pad[0x1d0];
    float f1;
    float f2;
    float f3;
};

void Target::copyFrom(const Source* src) {
    f1 = src->a;
    f2 = src->b;
    f3 = src->c;
}

