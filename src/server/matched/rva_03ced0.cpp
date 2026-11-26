struct LaggedGenerator
{
    unsigned int state[4];       // 0x00
    unsigned int mask[4];        // 0x10
    unsigned int shiftRight[4];  // 0x20
    unsigned int prevState[4];   // 0x30
    unsigned int shiftLeft[4];   // 0x40
    unsigned int maskShift[4];   // 0x50

    unsigned int Step();
};

unsigned int LaggedGenerator::Step()
{
    unsigned int w0 = state[0];
    unsigned int t0 = ((w0 << shiftLeft[0]) ^ w0) >> shiftRight[0];
    t0 ^= (w0 & mask[0]) << maskShift[0];
    state[0] = t0;

    unsigned int w1 = state[1];
    unsigned int t1 = ((w1 << shiftLeft[1]) ^ w1) >> shiftRight[1];
    t1 ^= (w1 & mask[1]) << maskShift[1];
    state[1] = t1;

    unsigned int w2 = state[2];
    unsigned int t2 = ((w2 << shiftLeft[2]) ^ w2) >> shiftRight[2];
    t2 ^= (w2 & mask[2]) << maskShift[2];
    state[2] = t2;

    unsigned int w3 = state[3];
    unsigned int t3 = ((w3 << shiftLeft[3]) ^ w3) >> shiftRight[3];
    t3 ^= (w3 & mask[3]) << maskShift[3];
    state[3] = t3;

    return t0 ^ t1 ^ t2 ^ t3;
}
