struct Holder
{
    void* value;
};

struct Node
{
    Holder* holder;
    unsigned int unused;
    unsigned int count;
};

struct Container
{
    Node* node;

    void* GetValue();
};

void* Container::GetValue()
{
    if (node->count <= 0)
        return 0;

    return node->holder->value;
}
