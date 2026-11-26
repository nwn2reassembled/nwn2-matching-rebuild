struct Entry
{
    char padding[0x44];
    void* value;
};

class Container
{
public:
    void* GetValue(int index);

private:
    char padding[0x284];
    int count;
    Entry* entries;
};

void* Container::GetValue(int index)
{
    if (index < 0 || index >= count)
        return 0;

    return entries[index].value;
}
