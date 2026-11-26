struct Item
{
    char pad[0x44];
    void* value;
};

class Container
{
public:
    Item* Get(int index);

private:
    char pad[0x284];
    int count;
    Item* items;
};

Item* Container::Get(int index)
{
    if (index >= 0 && index < count)
    {
        Item* p = items;
        if (p[index].value)
            return p + index;
    }
    return 0;
}
