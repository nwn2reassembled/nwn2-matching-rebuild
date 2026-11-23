struct Legacy {
    static int __stdcall accept(int a, int b, int c, int d);
};

int __stdcall Legacy::accept(int a, int b, int c, int d) {
    return 1;
}
