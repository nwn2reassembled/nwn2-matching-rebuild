struct Entry {
    int id;
    char data[96];
};

struct Container {
    char padding[0x4e8];
    Entry* entries;
    int unused;
    int count;

    Entry* Find(int id);
};

Entry* Container::Find(int id) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].id == id)
            return &entries[i];
    }
    return 0;
}
