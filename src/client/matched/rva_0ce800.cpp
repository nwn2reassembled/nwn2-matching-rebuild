struct Node {
    Node* /*+0x0*/ field0;
    Node* next; // +0x4
};

class ListHolder {
public:
    void* /*+0x0*/ field0;
    Node* nodes; // +0x4

    Node* tail();
};

Node* ListHolder::tail()
{
    Node* node = this->nodes;
    if (node == 0)
        return 0;
    while (node->next != 0)
        node = node->next;
    return node;
}
