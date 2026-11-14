struct LegacyObj {
    void* placeholder;
    unsigned int data;
    unsigned int findFirstSetBit() const;
};

unsigned int LegacyObj::findFirstSetBit() const {
    for (int i = 0; i < 18; ++i) {
        if (data & (1u << i)) {
            return 1u << i;
        }
    }
    return static_cast<unsigned int>(-1);
}
