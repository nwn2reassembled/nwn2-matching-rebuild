struct Legacy {
    char pad1[16];
    unsigned int src;
    char pad2[26];
    unsigned char dest[4];

    void copy();
};

void Legacy::copy() {
    *reinterpret_cast<unsigned int*>(dest) = src;
}

