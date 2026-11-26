struct Node {
    Node* head;  // field at offset 0
    Node* next;  // field at offset 4
};

Node* __cdecl ListNext(Node** list, Node* node)
{
    if (node == 0)
        return *list;

    Node* first = *list;
    if (first->head == node)
        return 0;

    return node->next;
}
