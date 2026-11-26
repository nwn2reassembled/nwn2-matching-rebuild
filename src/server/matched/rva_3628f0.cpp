struct Entry {
    char pad0[0x32c];
    int state;
    char pad1[8];
};

struct Table {
    int count;
    Entry* entries;
    int IsStateOne(int index) const;
};

int Table::IsStateOne(int index) const {
    if (entries != 0 && index >= 0 && index < count && entries[index].state == 1) {
        return 1;
    }
    return 0;
}
