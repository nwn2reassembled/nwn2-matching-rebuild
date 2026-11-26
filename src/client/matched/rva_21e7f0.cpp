struct Entry {
    int field_0;
    int x;
    int y;
};

struct Container {
    unsigned char pad[0xa8];
    Entry** entries;
    int count;
    void ClearEntries();
};

void Container::ClearEntries() {
    for (unsigned short i = 0; i < count; i++) {
        Entry* e = entries[i];
        e->x = 0;
        e->y = 0;
    }
}
