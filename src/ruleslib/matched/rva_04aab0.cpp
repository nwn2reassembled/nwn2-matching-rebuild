struct X {
    X* f();
};

X* X::f() {
    *((int*)this + 1) = 0;
    *((int*)this + 2) = 0;
    *((int*)this + 3) = 0;
    *(int*)this = -1;
    return this;
}
