struct Item
{
    unsigned int id;
};

struct Node
{
    Node* prev;
    Node* next;
    Item* item;
};

struct Container
{
    char unknown[0x184];
    Node* first;

    bool HasItem(unsigned int id);
};

bool Container::HasItem(unsigned int id)
{
    Node* node = first;
    if (node != 0)
    {
        do
        {
            Item* item = node->item;
            if (item != 0 && item->id == id)
                return true;
            node = node->next;
        }
        while (node != 0);
    }
    return false;
}
