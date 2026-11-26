class CObj
{
public:
    unsigned long m_pad[14];
    unsigned long m_field38;

    unsigned long GetField38();
};

unsigned long CObj::GetField38()
{
    return m_field38;
}
