struct Entry {
    int unknown0;
    unsigned short value;
};

struct Node {
    int unknown0;
    Node* next;
    Entry* entry;
};

struct Container {
    char reserved[0x184];
    Node* head;
    Node* GetNode(int index);
};

Node* Container::GetNode(int index)
{
    Node* node = head;
    if (!node)
        return 0;

    Entry* entry = node->entry;
    unsigned short previous = entry->value;

    if (index == 0)
        return node;

    int count = 0;
    for (;;) {
        unsigned short current = entry->value;
        if (current != previous) {
            previous = current;
            ++count;
        }

        if (count == index)
            return node;

        node = node->next;
        if (!node)
            return 0;

        entry = node->entry;
        if (!entry)
            return 0;
    }
}
