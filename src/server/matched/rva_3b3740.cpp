// nwn2server.exe RVA 0x3b3740

struct Entry {
    unsigned char pad0[8];
    void* value;   // +0x08
};

Entry* const g_defaultEntry = reinterpret_cast<Entry*>(0x008743a8);

void* GetEntryValue(Entry* entry)
{
    if (entry == 0)
        return g_defaultEntry;
    return entry->value;
}
