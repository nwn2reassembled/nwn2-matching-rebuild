struct Legacy {
    char pad0[12];
    volatile short s;
    char pad1[2];
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
    volatile int e;
    volatile int f;
    volatile int g;
    char pad2[4];
    volatile char h;
    volatile int i;

    int init();
};

int Legacy::init()
{
    b = 0;      // [ecx+0x14]
    c = 0;      // [ecx+0x18]
    i = 0;      // [ecx+0x34]
    s = 0;      // WORD at [ecx+0xc]
    a = 0;      // [ecx+0x10]
    d = 0;      // [ecx+0x1c]
    e = 0;      // [ecx+0x20]
    f = 0;      // [ecx+0x24]
    g = 0;      // [ecx+0x28]
    h = 5;      // BYTE at [ecx+0x30]
    return 1;
}

