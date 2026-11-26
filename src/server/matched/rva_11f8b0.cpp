struct Entry {
    int id;    // +0x0
    int key;   // +0x4
};

class Container {
public:
    int Find(int key);

    unsigned char _unused[0x20];
    Entry* entries;   // +0x20
    int count;        // +0x24
};

int Container::Find(int key)
{
    int count = this->count;
    int i = 0;
    if (count > 0) {
        Entry* entries = this->entries;
        do {
            if (entries[i].key == key)
                return entries[i].id;
            i = i + 1;
        } while (i < count);
    }
    return 0;
}
