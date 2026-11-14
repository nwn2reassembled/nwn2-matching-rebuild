struct Legacy {
    void foo(unsigned char);
};

void Legacy::foo(unsigned char offset) {
    if (offset < 10u) {
        unsigned char* ptr = reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+0x88+offset);
        *ptr += 255;
    }
}
