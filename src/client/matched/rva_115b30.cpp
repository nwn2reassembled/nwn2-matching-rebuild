struct EffectBlock {
    unsigned char raw[0x16B4];

    void __fastcall Clear(EffectBlock* target);
};

void EffectBlock::Clear(EffectBlock* target) {
    unsigned short *p;
    int i;

    p = (unsigned short *)&target->raw[0x94];
    for (i = 0x11E; i != 0; --i) {
        p[0] = 0;
        p += 2;
    }

    p = (unsigned short *)&target->raw[0x988];
    for (i = 0x1E; i != 0; --i) {
        p[0] = 0;
        p += 2;
    }

    p = (unsigned short *)&target->raw[0xA7C];
    for (i = 0x13; i != 0; --i) {
        p[0] = 0;
        p += 2;
    }

    *(unsigned int *)&target->raw[0x16AC] = 0;
    *(unsigned int *)&target->raw[0x16A8] = 0;
    *(unsigned int *)&target->raw[0x16B0] = 0;
    *(unsigned int *)&target->raw[0x16A0] = 0;
    *(unsigned short *)&target->raw[0x494] = 1;
}
