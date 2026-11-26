struct Node {
    Node* prev;
    Node* next;
    /* ...payload... */
};

struct NodeList {
    Node* head;
    Node* tail;
};

void NodeList_Remove(NodeList* list, Node* node)
{
    Node* prev = node->prev;
    Node* next = node->next;

    if (prev != 0)
        prev->next = next;
    else
        list->head = next;

    if (next != 0)
        next->prev = prev;
    else
        list->tail = prev;
}
