struct Node {
    unsigned char pad0[0xC];
    Node* next; // +0xC
};

struct NodeList {
    Node* head;   // +0x0
    Node* tail;   // +0x4
    Node* anchor; // +0x8
    void Add(Node* node);
};

void NodeList::Add(Node* node)
{
    if (this->head == 0 && this->anchor == 0) {
        this->head = node;
        this->anchor = node;
        this->tail = node;
        return;
    }
    if (this->tail == this->anchor) {
        this->anchor = node;
    }
    node->next = this->tail->next;
    this->tail->next = node;
    this->tail = node;
}
