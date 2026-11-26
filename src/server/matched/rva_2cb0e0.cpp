struct X {
    X* self();
};

X* X::self() {
    return this;
}
