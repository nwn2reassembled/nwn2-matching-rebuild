struct NetSession {
    char pad_0[0xA];
    unsigned short field_0xa;
    char pad_c[4];
    unsigned int field_0x10;

    int __thiscall IsSpecial() const;
};

int NetSession::IsSpecial() const {
    unsigned short w = field_0xa;
    if (w == 0x10 || w == 0x11) {
        return 1;
    }
    return field_0x10 != 0;
}
