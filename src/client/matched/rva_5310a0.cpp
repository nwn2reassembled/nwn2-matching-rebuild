class List;

class Node {
public:
    Node* prev;
    Node* next;
};

class List {
public:
    Node* head;
    Node* tail;
    unsigned long count;

    void __cdecl InsertAfter(Node* anchor, Node* node);
};

void List::InsertAfter(Node* anchor, Node* node)
{
    if (head == 0) {
        head = node;
        node->next = node;
        node->prev = node;
    } else {
        node->prev = anchor;
        node->next = anchor->next;
        anchor->next->prev = node;
        anchor->next = node;
    }
    ++count;
}
