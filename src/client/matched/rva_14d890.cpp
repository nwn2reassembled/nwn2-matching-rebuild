struct Entry {
    int pad[7];
    int key;
};

class Container {
public:
    Entry* entries;   // +0x00
    int pad;
    int count;        // +0x08
    Entry* FindEntry(int key);
};

Entry* Container::FindEntry(int key)
{
    int count = this->count;

    for (int i = 0; i < count; ++i) {
        if (this->entries[i].key == key) {
            return &this->entries[i];
        }
    }
    return 0;
}
