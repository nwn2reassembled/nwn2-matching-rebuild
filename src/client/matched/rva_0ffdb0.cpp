struct Inner
{
    char m_pad[0xd0];
    Inner* m_target;
};

struct Outer
{
    char m_pad[0x1c8];
    Inner* m_items[4];

    Inner* GetInner();
};

Inner* Outer::GetInner()
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_items[i] != 0)
            return m_items[i]->m_target;
    }
    return 0;
}
