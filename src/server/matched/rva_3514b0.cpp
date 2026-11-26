struct C
{
    int m_reserved;
    int m_value;
    int IsSpecial() const;
};

int C::IsSpecial() const
{
    if (m_value == 0x0e)
        return 1;
    if (m_value == 0x38)
        return 1;
    return m_value == 0x39;
}
