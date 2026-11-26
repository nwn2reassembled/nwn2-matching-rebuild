class CNWSStats
{
public:
    char m_pad0[0x5c4];
    signed char m_base;
    char m_pad1;
    char m_levels[3];
    char m_pad2;
    unsigned char m_bonus;

    int GetLevelSum(int idx);
};

int CNWSStats::GetLevelSum(int idx)
{
    int value =
        (int)(unsigned char)m_levels[idx] +
        (int)m_bonus +
        (int)m_base;

    if (value < 0)
        return 0;
    if (value > 100)
        value = 100;
    return value;
}
