struct Node
{
    /*+0x00*/ Node* prev;
    /*+0x04*/ Node* next;
    /*+0x08*/ void* value;
};

void* __stdcall ListPop(Node** head)
{
    Node* first = *head;
    if (first == 0)
        return 0;

    Node* next = first->next;
    if (next == 0)
    {
        *head = 0;
        return 0;
    }

    *head = next;
    return next->value;
}
