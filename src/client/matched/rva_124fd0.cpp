struct Entry
{
    int unused;
    int value;
};

struct Container
{
    char padding[0x44];
    Entry* entries;

    int GetValue(int index);
};

int Container::GetValue(int index)
{
    return entries[index].value;
}
