struct Node
{
    char pad[8];
    Node* next;
    char gap[0x21];
    bool flag;
};

Node* FindNode(Node* p)
{
    while (!p->next->flag)
        p = p->next;
    return p;
}
