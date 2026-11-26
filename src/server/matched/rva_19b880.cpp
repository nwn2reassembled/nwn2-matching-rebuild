class CNWSEngine {
public:
    unsigned char GetEngineFlag(unsigned char index);
    unsigned char m_pad[0x5cb];
    unsigned char m_engineFlags[9];
};

unsigned char CNWSEngine::GetEngineFlag(unsigned char index)
{
    if (index < 9)
        return m_engineFlags[index];
    return 0;
}
