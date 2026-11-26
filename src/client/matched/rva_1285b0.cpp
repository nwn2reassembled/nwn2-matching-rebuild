struct Entry
{
    int value;
    int id;
};

struct Table
{
    int reserved[8];
    Entry* entries;
    int count;

    int Find(int id) const;
};

int Table::Find(int id) const
{
    int index = 0;
    while (index < count)
    {
        if (entries[index].id == id)
            return entries[index].value;
        ++index;
    }
    return 0;
}
