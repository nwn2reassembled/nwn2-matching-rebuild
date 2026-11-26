struct Node {
    unsigned field_00;
    unsigned field_04;
    unsigned field_08;
    unsigned field_0C;
    Node*    next;    // +0x10
    int      state;   // +0x14, zero marks a stopped/available node
    unsigned field_18;

    Node* FirstStopped();
};

Node* Node::FirstStopped()
{
    Node* p = this;
    while (p != 0 && p->state != 0)
        p = p->next;
    if (p == 0)
        return 0;
    return p->state == 0 ? p : 0;
}
