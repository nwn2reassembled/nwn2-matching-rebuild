class Server
{
    char m_pad[0x31c];
    unsigned long m_statusFlags;

public:
    unsigned long GetStatusFlags();
};

unsigned long Server::GetStatusFlags()
{
    return m_statusFlags;
}
