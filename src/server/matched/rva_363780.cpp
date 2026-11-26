struct C {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    C* Reset();
};

C* C::Reset() {
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m0 = 0;
    m4 = 0;
    mc = 0;
    m8 = 0;
    return this;
}
