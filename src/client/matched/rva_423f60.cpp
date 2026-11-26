struct ClampedValue {
    int pad[0x4C];      // 0x000..0x12C
    int value;          // 0x130

    bool __thiscall IsWithinLimit();
};

bool ClampedValue::IsWithinLimit() {
    int v = this->value;
    if (v >= 0x1C) {
        v = 0x1C;
    }
    return v < 0x1C;
}
