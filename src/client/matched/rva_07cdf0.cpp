class CValueHolder
{
    bool m_useFirst;
    int m_first;
    char m_reserved[0x44];
    int m_second;
public:
    int GetValue() const;
};

int CValueHolder::GetValue() const
{
    return m_useFirst ? m_first : m_second;
}
