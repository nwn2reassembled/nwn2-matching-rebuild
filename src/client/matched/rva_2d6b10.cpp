struct Node {
    Node* first;   // +0x00
    int kind;      // +0x04
    int pad[7];    // +0x08 .. +0x23
    int field_24;  // +0x24
};

unsigned long __fastcall QueryField(Node** pp)
{
    Node* n = *pp;
    if (n->kind <= 2)
        return 0;
    return n->first->field_24;
}
