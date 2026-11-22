class C {
public:
    unsigned char func(char *ptr);
};

unsigned char C::func(char *ptr) { return ptr[0x53]; }
