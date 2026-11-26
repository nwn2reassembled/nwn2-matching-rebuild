class RuleTable {
public:
    int __stdcall GetEntryValue(int index);

private:
    unsigned char data[0x284];  // this+0x000 .. this+0x283
    int entryCount;             // this+0x284
    void* entries;              // this+0x288
};

struct Entry {
    int fields[17];  // offsets 0x00..0x40
    int value;       // offset 0x44
};

// sole emitted out-of-line function
int __stdcall RuleTable::GetEntryValue(int index) {
    if (index < 0 || index >= entryCount)
        return 0;
    return static_cast<Entry*>(entries)[index].value;
}
