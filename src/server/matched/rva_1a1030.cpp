struct Entry {
    unsigned short id;
    unsigned char  pad0[6];
    unsigned char  flags;
    unsigned char  pad1[3];
};

class EntryTable {
public:
    Entry* entries;
    int    count;
};

class Server {
public:
    unsigned char pad_0000[0x5d8];
    EntryTable*   entryTable;

    char GetEntryFlag(int id);
};

char Server::GetEntryFlag(int id)
{
    EntryTable* table = entryTable;
    int         n     = table->count;

    for (int i = 0; i < n; ++i) {
        if (table->entries[i].id == id) {
            return (char)table->entries[i].flags;
        }
    }
    return -1;
}
