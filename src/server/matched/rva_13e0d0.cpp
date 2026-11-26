struct Table {
    int count;   // +0x00
    int pad04;   // +0x04
    int stride;  // +0x08
    int pad0c;   // +0x0c
    int pad10;   // +0x10
    int base;    // +0x14

    int __cdecl Get(int index) const;
};

int __cdecl Table::Get(int index) const {
    if (index < 0 || index >= count)
        return 0;
    return stride * index + base;
}
