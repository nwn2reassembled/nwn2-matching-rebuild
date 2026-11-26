struct Entry
{
    int field0;
    int state;
    int field8;
};

struct EntryList
{
    Entry* data;
    int count;
};

class Owner
{
public:
    void ResetStates();

private:
    char reserved[0x5d8];
    EntryList* entries;
};

void Owner::ResetStates()
{
    for (int i = 0; i < entries->count; ++i)
        entries->data[i].state = 1;
}
