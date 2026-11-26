struct Entry {
    void *vtable;   // 0x0
    int field4;     // 0x4
    int field8;     // 0x8
};

class ServerObject {
public:
    void *pad00[42];        // 0x00 .. 0xa7
    Entry **entries;        // 0xa8
    int entryCount;         // 0xac

    void ClearEntries();
};

void ServerObject::ClearEntries() {
    for (unsigned short i = 0; i < entryCount; ++i) {
        Entry *e = entries[i];
        e->field4 = 0;
        e->field8 = 0;
    }
}
