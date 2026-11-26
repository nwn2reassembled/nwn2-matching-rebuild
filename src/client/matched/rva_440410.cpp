class Legacy {
public:
    void init();
};

void Legacy::init() {
    char *base = reinterpret_cast<char*>(this);
    *(int*)(base + 0x114) = 0;
    *(int*)(base + 0x118) = 0;
    *(int*)(base + 0x104) = 0;
    *(int*)(base + 0x108) = 0;
    *(int*)(base + 0xf4)  = 0;
    *(int*)(base + 0xf8)  = 0;
    *(int*)(base + 0xc4)  = 0;
    *(int*)(base + 0xc8)  = 0;
    *(int*)(base + 0xcc)  = 0;
    *(int*)(base + 0xd8)  = 0;
    *(int*)(base + 0xdc)  = 0;
    *(int*)(base + 0xe0)  = 0;
    *(int*)(base + 0xe4)  = 0;
    *(int*)(base + 0xd0)  = 0;
    *(int*)(base + 0xd4)  = 0;
    *(int*)(base + 0xe8)  = 0;
    *(int*)(base + 0xec)  = 0;
    *(int*)(base + 0x88)  = 0;
    *(int*)(base + 0x8c)  = 0;
    *(int*)(base + 0x90)  = 0;
    *(int*)(base + 0x9c)  = 0;
    *(int*)(base + 0xa0)  = 0;
    *(int*)(base + 0xa4)  = 0;
    *(int*)(base + 0xa8)  = 0;
    *(int*)(base + 0x94)  = 0;
    *(int*)(base + 0x98)  = 0;
    *(int*)(base + 0xac)  = 0;
    *(int*)(base + 0xb0)  = 0;
    *(int*)(base + 0x50)  = 0;
    *(int*)(base + 0x54)  = 0;
    *(int*)(base + 0x58)  = 0;
    *(int*)(base + 0x5c)  = 0;
    *(int*)(base + 0x60)  = 0;
    *(int*)(base + 0x64)  = 0;
    *(int*)(base + 0x68)  = 0;
    *(int*)(base + 0x6c)  = 0;
    *(int*)(base + 0x70)  = 0;
    *(int*)(base + 0x44)  = 0;
    *(int*)(base + 0x48)  = 0;
    *(int*)(base + 0x14)  = 0;
    *(int*)(base + 0x18)  = 0;
    *(int*)(base + 0x1c)  = 0;
    *(int*)(base + 0x20)  = 0;
    *(int*)(base + 0x24)  = 0;
    *(int*)(base + 0x28)  = 0;
    *(int*)(base + 0x2c)  = 0;
    *(int*)(base + 0x30)  = 0;
    *(int*)(base + 0x34)  = 0;
    *(int*)(base + 0x8)   = 0;
    *(int*)(base + 0xc)   = 0;
}

