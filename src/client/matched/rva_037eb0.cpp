class Node {
public:
    void InsertAfter(Node* p);
private:
    char reserved[0x1cc];
    Node* prev;
    Node* next;
};

void Node::InsertAfter(Node* p)
{
    p->prev = this;
    p->next = next;
    if (next != 0)
        next->prev = p;
    next = p;
}
