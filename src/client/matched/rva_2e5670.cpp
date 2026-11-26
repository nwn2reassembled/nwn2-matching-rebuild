struct ControlFlags {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
};

struct Control {
    unsigned char pad[0x2fc];
    ControlFlags flags;
    unsigned char GetState();
};

unsigned char Control::GetState() {
    if (this->flags.bit1)
        return 0x2;
    unsigned char b = this->flags.bit0;
    return b;
}
