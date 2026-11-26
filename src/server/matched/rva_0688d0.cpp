struct ListNode {
    char reserved[0x1cc];
    ListNode* prev;
    ListNode* next;

    void InsertAfter(ListNode* node);
};

void ListNode::InsertAfter(ListNode* node)
{
    node->prev = this;
    node->next = next;
    if (next != 0)
        next->prev = node;
    next = node;
}
