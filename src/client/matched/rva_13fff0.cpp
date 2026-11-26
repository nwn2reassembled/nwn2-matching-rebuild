struct Node {
    unsigned int pad00[8];
    unsigned int key;      // +0x20
    Node*        next;     // +0x24
};

struct Holder {
    unsigned char pad[0x818];
    Node* list;           // +0x818
};

int __cdecl FindInList(Holder* holder, unsigned int key)
{
    Node* node = holder->list;
    while (node != 0) {
        if (node->key == key)
            return 1;
        node = node->next;
    }
    return 0;
}
