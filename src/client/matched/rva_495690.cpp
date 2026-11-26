struct Legacy {
    int dummy;
    void init();
};

void Legacy::init() {
    *((int*)((char*)this + 0x38)) = 0;
    *((int*)((char*)this + 0x30)) = 0;
    *((int*)((char*)this + 0x2c)) = 0;
    *((int*)((char*)this + 0x3c)) = 0;
    *((int*)((char*)this + 0xc )) = 0;
    *((int*)((char*)this + 0x10)) = 0;
    *((int*)((char*)this + 0x18)) = 0;
    *((int*)((char*)this + 0x1c)) = 0;
    *((int*)((char*)this + 0x20)) = 0;
    *((int*)((char*)this + 0x24)) = 0;
    *((int*)((char*)this + 0x14)) = 0;
    *((int*)((char*)this + 0x34)) = 0;
    *((int*)((char*)this + 0x28)) = 0;
    *((int*)((char*)this + 0x48)) = 0;
}

