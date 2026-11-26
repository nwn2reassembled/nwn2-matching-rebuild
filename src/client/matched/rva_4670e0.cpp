struct Node {
    int pad_00;
    int pad_04;
    int pad_08;
    int pad_0C;
    int pad_10;
    int pad_14;
    int pad_18;
    int pad_1C;
    int pad_20;
    int pad_24;
    int pad_28;
    Node* next; // +0x2C
    Node* prev; // +0x30
};

class List {
public:
    int pad_00;
    int pad_04;
    int pad_08;
    int pad_0C;
    int pad_10;
    int pad_14;
    Node* head; // +0x18
    Node* tail; // +0x1C

    void Append(Node* item);
};

// RVA 0x4670e0: thiscall, this in ecx, item at [esp+4], popped by callee
void List::Append(Node* item) {
    *(int*)((char*)item + 0x10) = (int)this;
    item->next = tail;
    item->prev = 0;
    Node* oldTail = tail;
    if (oldTail != 0) {
        oldTail->prev = item;
        tail = item;
    } else {
        head = item;
        tail = item;
    }
}
