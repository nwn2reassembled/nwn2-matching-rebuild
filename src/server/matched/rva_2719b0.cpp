struct Legacy {
    int dummy;
    int divisor;
    int func(int* p);
};

int Legacy::func(int* p) {
    return *p % this->divisor;
}
