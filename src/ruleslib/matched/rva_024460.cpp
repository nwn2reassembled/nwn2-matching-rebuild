struct Legacy {
    unsigned char data[13];
    static int __stdcall check(Legacy* ptr);
};

int __stdcall Legacy::check(Legacy* ptr) {
    return (ptr->data[12] >> 1) & 1;
}
