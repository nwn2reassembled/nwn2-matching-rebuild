struct Item
{
    char padding[0x44];
    int value;
};

class Container
{
public:
    int GetItemValue(int index) const;

private:
    char padding[0x284];
    int count;
    Item* items;
};

int Container::GetItemValue(int index) const
{
    if (index < 0 || index >= count)
        return 0;

    return items[index].value;
}
