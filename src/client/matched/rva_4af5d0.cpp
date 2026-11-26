class StrTable {
public:
    char pad0[0x38];
    unsigned short count;   // +0x38
    wchar_t* entries;       // +0x3c

    int Contains(wchar_t ch);
};

int StrTable::Contains(wchar_t ch) {
    wchar_t* p = entries;
    if (!p)
        return 0;
    unsigned short n = count;
    for (unsigned short i = 0; i < n; ++i) {
        if (p[i] == ch)
            return 1;
    }
    return 0;
}
