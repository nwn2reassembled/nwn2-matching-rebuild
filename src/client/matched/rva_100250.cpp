class Child
{
public:
    char m_pad[0xfc];
    unsigned char m_flag;
};

class Holder
{
public:
    char m_pad0[0x1c8];
    Child* m_children[4];
    char m_pad1[0x2fc];
    unsigned char m_flag;

    void SetFlag(unsigned char value);
};

void Holder::SetFlag(unsigned char value)
{
    m_flag = value;
    for (int i = 0; i < 4; ++i)
    {
        Child* child = m_children[i];
        if (child != 0)
            child->m_flag = value;
    }
}
