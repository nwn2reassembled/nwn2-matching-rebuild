struct S {
    int f(int, int, int);
};

int S::f(int a, int b, int c) {
    if (c == 0)
        return 2;
    else
        return 1;
}

