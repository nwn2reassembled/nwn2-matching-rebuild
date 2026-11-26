struct Node {
    Node* next;          // offset 0x00
    unsigned char pad[0x11];
    unsigned char flag;  // offset 0x15, nonzero marks a match
};

// Returns the predecessor of the first node whose flag is set.
Node* FindPrevFlagged(Node* head)
{
    Node* prev = head;
    while (prev->next->flag == 0) {
        prev = prev->next;
    }
    return prev;
}
