struct C
{
    unsigned char m_flag;
    unsigned char m_pad0[7];
    int m_value;
    unsigned char m_pad1[68];
    int m_alt;

    int Get() const;
};

int C::Get() const
{
    if (m_flag != 0)
        return m_value;

    return m_alt;
}
