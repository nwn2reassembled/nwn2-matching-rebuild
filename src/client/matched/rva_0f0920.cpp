struct C
{
    char pad0[0x254];
    unsigned int m_value;
    char pad1[0xC];
    unsigned int m_flags;

    void SetValue(unsigned int value);
};

void C::SetValue(unsigned int value)
{
    if (m_value != value)
    {
        m_flags |= 0x7C0000;
        m_value = value;
    }
}
