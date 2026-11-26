struct Node
{
    unsigned char pad[0x8];
    int field08;
};

class Holder
{
    unsigned char pad_[0x4];
    Node* m_node;

public:
    int GetField();
};

int Holder::GetField()
{
    if (m_node != 0)
        return m_node->field08;
    return 0;
}
