struct Node
{
    char pad[0x10];
    Node* next;
};

class Widget
{
public:
    unsigned int field_0;
    unsigned int field_4;
    Node* cursor;
    bool Advance();
};

// Advances the cursor if the current node has a successor.
bool Widget::Advance()
{
    Node* next = cursor->next;
    if (next)
    {
        cursor = next;
        return true;
    }
    return false;
}
