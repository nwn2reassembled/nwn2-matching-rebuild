struct Node {
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

void List_PushBack(List* list, Node* node)
{
    Node* tail = list->tail;
    node->next = 0;
    node->prev = tail;
    if (tail != 0) {
        tail->next = node;
        list->tail = node;
    } else {
        list->head = node;
        list->tail = node;
    }
}
