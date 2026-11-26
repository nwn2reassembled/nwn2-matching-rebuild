class C {
public:
    int f0;
    int f4;
    int f8;
    int fC;
    int GetValue();
};

int C::GetValue() { return fC + 0x3C; }
