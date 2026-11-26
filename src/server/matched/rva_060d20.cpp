struct Node {
    Node* next;      // offset 0x00
    char  pad[17];   // offsets 0x04..0x14
    bool  flag;      // offset 0x15
};

Node* FindNodeBeforeFlagged(Node* link)
{
    while (link->next->flag == 0)
        link = link->next;
    return link;
}
