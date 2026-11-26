struct Node {
    void* unk0;     // +0x0
    Node* next;     // +0x4
    void* value;    // +0x8
};

struct List {
    Node* head;     // +0x0
};

Node* FindNode(List* list, void* value)
{
    Node* node = list->head;
    while (node != 0) {
        if (node->value == value)
            return node;
        node = node->next;
    }
    return 0;
}
