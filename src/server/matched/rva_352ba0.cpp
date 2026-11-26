struct Thing
{
    unsigned short m_value;
    unsigned int m_count;
    unsigned char m_state;
    Thing* Init();
};

Thing* Thing::Init()
{
    m_value = 0xFFFFu;
    m_count = 1u;
    m_state = 0u;
    return this;
}
