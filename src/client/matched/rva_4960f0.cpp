typedef char Entry[244];

class EntryTable {
public:
    int count;
    Entry* entries;

    Entry* GetEntry(int index);
};

Entry* EntryTable::GetEntry(int index) {
    if (entries != 0 && index >= 0 && index < count) {
        return &entries[index];
    }
    return 0;
}
