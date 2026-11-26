struct ServerState {
    void EnsureInitialized();

    unsigned char pad_00[0x18];
    unsigned long flags_18;
    unsigned long lo_1c;
    unsigned long hi_20;
    unsigned char pad_24[0x14];
    unsigned long lo_38;
    unsigned long hi_3c;
};

void ServerState::EnsureInitialized() {
    if (flags_18 == 0) {
        unsigned long a = lo_38;
        unsigned long b = hi_3c;
        lo_1c = a;
        hi_20 = b;
        flags_18 = 1;
    }
}
