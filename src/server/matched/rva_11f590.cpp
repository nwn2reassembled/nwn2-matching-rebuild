struct ValueNode
{
    int reserved0;
    int reserved1;
    int reserved2;
    int reserved3;
    int value;
};

struct ValueHolder
{
    int reserved0;
    int reserved1;
    int reserved2;
    int reserved3;
    ValueNode* node;
    int GetValue();
};

int ValueHolder::GetValue()
{
    if (node != 0)
    {
        return node->value;
    }
    return 0;
}
