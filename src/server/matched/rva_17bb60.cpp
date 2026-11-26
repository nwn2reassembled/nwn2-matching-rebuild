struct Data {
    unsigned char pad[4];
    unsigned short id;   // +0x04
};

struct ListNode {
    unsigned char pad[4];
    ListNode* next;      // +0x04
    Data* data;          // +0x08
};

struct Obj {
    unsigned char pad[0x184];
    ListNode* list;      // +0x184
};

int __fastcall CountDistinctValueTransitions(Obj* self)
{
    ListNode* node = self->list;
    if (node == 0)
        return 0;

    int result = 0;
    Data* d = node->data;
    if (d != 0)
        result = 1;

    unsigned short prev = d->id;

    for (;;)
    {
        unsigned short cur = d->id;
        if (cur != prev)
        {
            prev = cur;
            result++;
        }

        node = node->next;
        if (node == 0)
            break;

        d = node->data;
    }

    return result;
}
