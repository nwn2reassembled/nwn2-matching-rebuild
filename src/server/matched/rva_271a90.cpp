struct Legacy {
    int placeholder;
    int divisor;

    int foo(int *p);
};

int Legacy::foo(int *p) {
    return *p % divisor;
}

