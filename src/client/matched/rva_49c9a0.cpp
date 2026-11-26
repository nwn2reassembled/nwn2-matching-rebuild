struct QualityHolder {
    unsigned char pad0[0x7a];
    short level; // +0x7a, signed short

    char GetTier();
};

char QualityHolder::GetTier() {
    short v = this->level;
    if (v <= 30)
        return 3;
    if (v >= 70)
        return 2;
    return 1;
}
