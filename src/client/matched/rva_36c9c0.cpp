struct Entry
{
    unsigned char pad[0x5c];
    unsigned char flag;
};

struct Manager
{
    void Clear();
    unsigned char pad[0x170];
    Entry** entries;
    int extra;
    int count;
};

void Manager::Clear()
{
    int n = count;
    for (int i = 0; i < n; ++i)
    {
        if (count > 0 && i >= 0 && i < count)
        {
            Entry* e = entries[i];
            if (e != 0)
            {
                e->flag = 0;
            }
        }
    }
}
