struct C
{
    int m_unused;
    C* m_link;
    void SetLink(C* p);
};

void C::SetLink(C* p)
{
    if (p != 0 && p != this)
        m_link = p;
}
