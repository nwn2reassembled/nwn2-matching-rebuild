struct Item
{
    int key;
    int data[7];
};

struct ItemTable
{
    Item* items;
    int capacity;
    int count;

    Item* Find(int key);
};

Item* ItemTable::Find(int key)
{
    for (int i = 0; i < count; ++i)
    {
        if (items[i].key == key)
            return &items[i];
    }
    return 0;
}
