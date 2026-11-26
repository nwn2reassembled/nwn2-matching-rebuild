struct Node
{
    char pad0[0x10];
    Node* next;
};

struct Cursor
{
    char pad0[4];
    Node* current;

    bool Advance();
};

bool Cursor::Advance()
{
    Node* next = current->next;
    if (next != 0)
    {
        current = next;
        return true;
    }
    return false;
}
