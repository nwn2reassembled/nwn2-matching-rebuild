struct Entry {
    char pad[0x71c];
    int key0;   // +0x71c
    int key1;   // +0x720
};

struct Widget {
    char pad[0xbd4];
    Entry** items;  // +0xbd4
    int count;      // +0xbd8
    Entry* Find(int key0, int key1);
};

Entry* Widget::Find(int key0, int key1)
{
    for (int i = 0; i < count; i++) {
        Entry* e = items[i];
        if (e != 0 && e->key0 == key0 && e->key1 == key1)
            return e;
    }
    return 0;
}
