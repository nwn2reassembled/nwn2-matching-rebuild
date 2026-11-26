struct Box {
    int value;
    Box* assign(int v);
};

Box* Box::assign(int v) {
    value = v;
    return this;
}
