struct W2 {
    unsigned short w;
    unsigned short pad;
};

struct EffectDataBlock {
    unsigned char pad0[0x94];
    W2 a[0x100];               /* 0x094 .. 0x494 */
    unsigned short field494;   /* 0x494 */
    unsigned short pad496;     /* 0x496 */
    W2 a2[0x1E];               /* 0x498 .. 0x50C */
    unsigned char pad1[0x478]; /* 0x50C .. 0x988 */
    W2 b[0x1E];                /* 0x988 .. 0xA00 */
    unsigned char pad2[0x7C];  /* 0xA00 .. 0xA7C */
    W2 c[0x13];                /* 0xA7C .. 0xAC8 */
    unsigned char pad3[0xBD8]; /* 0xAC8 .. 0x16A0 */
    unsigned int f16A0;
    unsigned int f16A4;
    unsigned int f16A8;
    unsigned int f16AC;
    unsigned int f16B0;
};

void __fastcall ClearEffectDataBlock(void* unused, EffectDataBlock* data)
{
    unsigned short* p;
    int i;

    p = &data->a[0].w;
    for (i = 0x11E; i != 0; --i) {
        *p = 0;
        p += 2;
    }

    p = &data->b[0].w;
    for (i = 0x1E; i != 0; --i) {
        *p = 0;
        p += 2;
    }

    p = &data->c[0].w;
    for (i = 0x13; i != 0; --i) {
        *p = 0;
        p += 2;
    }

    data->f16AC = 0;
    data->f16A8 = 0;
    data->f16B0 = 0;
    data->f16A0 = 0;

    data->field494 = 1;
}
