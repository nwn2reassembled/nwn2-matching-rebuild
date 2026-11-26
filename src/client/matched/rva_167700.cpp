struct Entry {
    int reserved;
    int key;
    int value;
};

struct Node {
    int reserved;
    Node* next;
    Entry* entry;
};

struct List {
    Node* head;
};

struct Owner {
    char reserved[0x1008c];
    List* list;
    int Find(int key);
};

int Owner::Find(int key)
{
    Node* node = list->head;
    while (node != 0) {
        Entry* entry = node->entry;
        if (entry != 0 && entry->key == key) {
            return entry->value;
        }
        node = node->next;
    }
    return 0;
}
