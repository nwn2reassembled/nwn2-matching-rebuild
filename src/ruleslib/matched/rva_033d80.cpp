struct X {
    int get_flag(void* p);
};

int X::get_flag(void* p) {
    return (*(unsigned char*)((char*)p + 0x6d0) >> 1) & 1;
}
