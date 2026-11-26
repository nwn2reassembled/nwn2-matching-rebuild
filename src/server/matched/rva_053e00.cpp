struct Node
{
    int pad0;
    int pad4;
    Node* link8;
    char pad_0C[9];
    unsigned char flag15;
};

Node* advance_until_flag(Node* node)
{
    Node* n = node;
    while (!n->link8->flag15)
        n = n->link8;
    return n;
}
