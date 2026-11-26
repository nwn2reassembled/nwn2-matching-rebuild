struct CClass
{
    unsigned char GetValue(unsigned char index) const;

    char m_reserved[0x5cb];
    unsigned char m_values[9];
};

unsigned char CClass::GetValue(unsigned char index) const
{
    if (index < 9)
        return m_values[index];
    return 0;
}
