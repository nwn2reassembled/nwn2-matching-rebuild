struct Entry {
    int id;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
};

class Container {
public:
    Entry *entries;
    int field4;
    int count;

    Entry *FindEntry(int id);
};

Entry *Container::FindEntry(int id)
{
    int n = count;
    int i = 0;
    if (n > 0) {
        Entry *base = entries;
        Entry *p = base;
        for (; i < n; ++i) {
            if (p->id == id)
                return base + i;
            ++p;
        }
    }
    return 0;
}
