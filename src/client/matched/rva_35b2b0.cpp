struct Legacy {
    int dummy[45];        // 45 * 4 = 180 (0xB4) bytes of padding
    int data;             // DWORD at offset 0xB4
    bool isNonZero() const;
};

bool Legacy::isNonZero() const { return data != 0; }
