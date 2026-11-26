struct Node
{
    char pad0[8];
    Node* next;
    char pad1[0x21];
    unsigned char flag;
};

Node* FindPrevious(Node* p)
{
    while (p->next->flag == 0)
    {
        p = p->next;
    }
    return p;
}
