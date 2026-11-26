struct Node
{
    char pad0[0x1c8];
    unsigned int flags;
    char pad1[4];
    Node* next;

    void OrSubtreeFlags(unsigned int value);
};

void Node::OrSubtreeFlags(unsigned int value)
{
    flags |= value;
    if (next != 0)
    {
        Node** link = &next;
        do
        {
            Node* node = *link;
            node->flags |= value;
            link = &node->next;
        } while (*link != 0);
    }
}
