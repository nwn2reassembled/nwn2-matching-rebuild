class X {
public:
    static void __stdcall set_word(unsigned short* ptr, unsigned short val);
};

void __stdcall X::set_word(unsigned short* ptr, unsigned short val) {
    *ptr = val;
}

