struct KeyedValue {
    int reserved;
    unsigned key;
    void* value;
};

struct Node {
    int reserved;
    Node* next;
    KeyedValue* entry;
};

struct NodeList {
    Node* first;
};

class LookupTable {
    char reserved[0x1008c];
    NodeList* list;
public:
    void* Find(unsigned key);
};

void* LookupTable::Find(unsigned key) {
    Node* node = list->first;
    while (node != 0) {
        KeyedValue* value = node->entry;
        if (value != 0 && value->key == key) {
            return value->value;
        }
        node = node->next;
    }
    return 0;
}
