struct Target {
    unsigned char data[0x628];
    unsigned char value;
};

struct Caller {
    static void __stdcall setField(Target* p, unsigned char val);
};

void Caller::setField(Target* p, unsigned char val) {
    p->value = val;
}

