struct Legacy {
    char pad[44];
    int flag;
    int clear();
};

int Legacy::clear() {
    if (flag != 0)
        flag = 0;
    return 1;
}
