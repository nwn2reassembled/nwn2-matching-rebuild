struct C {
    int a;
    int b;
    int c;
    C* Reset();
};

C* C::Reset() {
    b = 0;
    c = 0;
    a = 0;
    return this;
}
