class ServerCharStats
{
public:
    void ClearAll();

    char m_pad[0x5DC];
    unsigned short m_stats[39]; // at 0x5DC..0x628
};

void ServerCharStats::ClearAll()
{
    m_stats[1] = 0xFFFF;
    m_stats[2] = 0xFFFF;
    m_stats[3] = 0xFFFF;
    m_stats[5] = 0xFFFF;
    m_stats[6] = 0xFFFF;
    m_stats[4] = 0xFFFF;
    m_stats[0] = 0xFFFF;
    m_stats[7] = 0xFFFF;
    m_stats[8] = 0xFFFF;
    m_stats[9] = 0xFFFF;
    m_stats[11] = 0xFFFF;
    m_stats[10] = 0xFFFF;
    m_stats[12] = 0xFFFF;
    m_stats[13] = 0xFFFF;
    m_stats[14] = 0xFFFF;
    m_stats[15] = 0xFFFF;
    m_stats[16] = 0xFFFF;
    m_stats[17] = 0xFFFF;
    m_stats[18] = 0xFFFF;
    m_stats[19] = 0xFFFF;
    m_stats[20] = 0xFFFF;
    m_stats[21] = 0xFFFF;
    m_stats[22] = 0xFFFF;
    m_stats[23] = 0xFFFF;
    m_stats[24] = 0xFFFF;
    m_stats[25] = 0xFFFF;
    m_stats[26] = 0xFFFF;
    m_stats[27] = 0xFFFF;
    m_stats[28] = 0xFFFF;
    m_stats[29] = 0xFFFF;
    m_stats[30] = 0xFFFF;
    m_stats[31] = 0xFFFF;
    m_stats[32] = 0xFFFF;
    m_stats[33] = 0xFFFF;
    m_stats[34] = 0xFFFF;
    m_stats[35] = 0xFFFF;
    m_stats[36] = 0xFFFF;
    m_stats[37] = 0xFFFF;
    m_stats[38] = 0xFFFF;
}
