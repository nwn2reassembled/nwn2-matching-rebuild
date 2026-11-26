struct S { unsigned short m(); };
unsigned short S::m() {
    unsigned short v;
    v |= 0xFFFFU;
    return v;
}
