class CState
{
public:
    int Check(unsigned long id, int value);

private:
    unsigned char m_reserved0[0x2344];
    int m_2344;
    unsigned char m_reserved1[0x2350 - 0x2348];
    int m_2350;
    int m_2354;
    int m_2358;
    unsigned char m_reserved2[0x2360 - 0x235c];
    int m_2360;
    unsigned long m_2364;
};

int CState::Check(unsigned long id, int value)
{
    if (m_2360 == 1 && m_2364 != id)
        return 0;

    if (m_2344 != 1)
        return 1;

    return m_2354 - m_2358 - m_2350 + 1000 >= value;
}
