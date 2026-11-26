struct Node {
    int value;
    Node* next;
};

struct NodeList {
    int reserved;
    int count;
    Node** entries;

    int CountNodes() const;
};

int NodeList::CountNodes() const {
    int total = 0;
    for (int i = 0; i < count; ++i) {
        Node* p = entries[i];
        while (p != 0) {
            ++total;
            p = p->next;
        }
    }
    return total;
}
