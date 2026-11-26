class EngineOptions {
public:
    unsigned long GetEnabledFeatureMask();

    unsigned char pad_000[0x404];
    unsigned long flags1;
    unsigned char pad_408[0x8C];
    unsigned long flags2;
};

unsigned long __thiscall EngineOptions::GetEnabledFeatureMask() {
    unsigned long mask = 0x80000;
    if (this->flags1 == 0) {
        mask = 0x480000;
        if (this->flags2 != 0)
            mask = 0x482000;
    }
    return mask;
}
