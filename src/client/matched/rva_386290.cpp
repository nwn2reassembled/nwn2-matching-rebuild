struct Object
{
    char pad_0000[0xa4];
    int value_a4;
    int value_a8;
    char pad_00ac[4];
    int value_b0;
    int value_b4;
    int value_b8;
    int value_bc;
    int value_c0;
    int value_c4;
    int value_c8;
    char pad_00cc[0x10];
    unsigned char flags_dc;

    bool ResetState();
};

bool Object::ResetState()
{
    flags_dc &= 0xfb;
    value_a4 = 0;
    value_a8 = 0;
    value_b0 = 0;
    value_b4 = 0;
    value_b8 = 0;
    value_bc = 0;
    value_c0 = 0;
    value_c4 = 0;
    value_c8 = 0;
    return true;
}
