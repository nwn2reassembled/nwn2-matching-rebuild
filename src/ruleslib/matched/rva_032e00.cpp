struct Legacy {
    static int __stdcall add4(int);
};

int __stdcall Legacy::add4(int value) {
    return value + 4;
}

