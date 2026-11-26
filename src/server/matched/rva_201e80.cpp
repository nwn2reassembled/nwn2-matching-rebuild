struct Other {
    char pad[2000];
    int key;
};

struct Finder {
    int reserved;
    int entries[18];
    int Find(Other* p);
};

int Finder::Find(Other* p) {
    for (int i = 0; i < 18; ++i) {
        if (entries[i] == p->key)
            return 1 << i;
    }
    return 0;
}
