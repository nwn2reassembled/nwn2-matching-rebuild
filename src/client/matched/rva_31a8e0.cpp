struct Item
{
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
};

class ItemList
{
public:
    Item* GetItem(int index);

private:
    char m_reserved[0x120];
    Item* m_items;
    int m_reserved2;
    int m_count;
};

Item* ItemList::GetItem(int index)
{
    if (index < 0 || index >= m_count)
        return 0;

    return &m_items[index];
}
