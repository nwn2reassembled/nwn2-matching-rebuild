struct ListNode {
    ListNode* prev;
    ListNode* next;
};

struct ListHead {
    ListNode* first;
    unsigned long field_4;
    unsigned long count;
};

void ListInsertAfter(ListHead* head, ListNode* node, ListNode* entry)
{
    if (head->first == 0)
    {
        head->first = entry;
        entry->next = entry;
        entry->prev = entry;
        head->count += 1;
        return;
    }

    entry->prev = node;
    entry->next = node->next;
    node->next->prev = entry;
    node->next = entry;
    head->count += 1;
}
