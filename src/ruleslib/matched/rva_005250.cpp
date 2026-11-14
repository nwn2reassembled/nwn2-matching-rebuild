class Legacy {
public:
    int dummy;
    int value;
    int check() const;
};

int Legacy::check() const {
    if (value == 0x28) return 1; // 40 decimal
    if (value == 0x24) return 1; // 36 decimal
    if (value == 0x4e) return 1; // 78 decimal
    if (value == 0x32) return 1; // 50 decimal
    if (value == 0x3b) return 1; // 59 decimal
    return 0;
}

