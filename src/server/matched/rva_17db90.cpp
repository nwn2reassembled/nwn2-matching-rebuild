struct Node {
    unsigned int tag;
    Node* next;
    int* value;
};

class KeyList {
    char reserved[0x184];
    Node* head;
public:
    bool Contains(int key);
};

bool KeyList::Contains(int key) {
    Node* node = head;
    while (node != 0) {
        int* value = node->value;
        if (value != 0 && *value == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}
