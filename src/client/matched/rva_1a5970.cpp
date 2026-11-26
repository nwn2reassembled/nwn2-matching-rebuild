struct Entry {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
};

struct Widget {
    char pad0[0xA84];   // up to +0xA84
    Entry* entries;     // +0xA84
    int count;          // +0xA88

    Entry* GetEntryAt(int index);
};

Entry* Widget::GetEntryAt(int index) {
    if (index < 0 || index >= count)
        return 0;
    return entries + index;
}
