struct Legacy {
    char dummy[6];
    unsigned char value;
    static unsigned char __stdcall getByte(const Legacy* p);
};

unsigned char Legacy::getByte(const Legacy* p) { return p->value; }

