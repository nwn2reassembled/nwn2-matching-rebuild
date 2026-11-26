class Node {
public:
    Node* prev;  // +0x00
    Node* next;  // +0x04
};

class List {
public:
    Node* head;  // +0x00
    Node* tail;  // +0x04

    static void MoveToFront(List* list, Node* node);
};

void List::MoveToFront(List* list, Node* node)
{
    Node* prev = node->prev;
    Node* next = node->next;

    if (prev == 0)
        return;

    prev->next = next;

    if (next != 0)
        next->prev = prev;
    else
        list->tail = prev;

    node->prev = 0;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
}
