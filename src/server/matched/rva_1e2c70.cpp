struct ServerListEntry {
    char pad[0x44];
    int active;
};

struct ServerContainer {
    char pad0[0x284];
    int count;
    ServerListEntry* entries;
    ServerListEntry* GetActiveEntry(int index);
};

ServerListEntry* ServerContainer::GetActiveEntry(int index)
{
    if (index < 0 || index >= this->count || this->entries[index].active == 0)
        return 0;
    return &this->entries[index];
}
