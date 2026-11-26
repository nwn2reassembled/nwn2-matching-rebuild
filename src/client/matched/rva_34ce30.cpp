struct CState
{
    char reserved[0xbe];
    unsigned char m_value;
};

struct CObject
{
    char reserved0[0x110];
    CState* m_state;
    char reserved1[0x7e4];
    unsigned char m_value;

    void SetValue(unsigned char value);
};

void CObject::SetValue(unsigned char value)
{
    m_value = value;
    if (m_state != 0)
    {
        m_state->m_value = value;
    }
}
