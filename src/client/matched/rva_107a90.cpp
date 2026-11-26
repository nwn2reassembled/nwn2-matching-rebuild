struct CData
{
    char m_pad[0x7ab7c];
    int m_first;
    int m_second;
};

class COuter
{
public:
    bool IsReady() const;

private:
    CData* m_p;
};

bool COuter::IsReady() const
{
    if (m_p)
        return m_p->m_second != 0 && m_p->m_first != 0;
    return false;
}
