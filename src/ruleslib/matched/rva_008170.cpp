struct LegacyObject {
    char filler[10];
    unsigned short value_at_10;
    char pad[4];
    int field_at_16;

    int legacyFunc() const;
};

int LegacyObject::legacyFunc() const {
    unsigned short val = value_at_10;
    if (val == 0x10 || val == 0x11)
        return 1;
    int other = field_at_16;
    return other != 0 ? 1 : 0;
}

