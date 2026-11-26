class CServer
{
public:
    int GetOffset414();
    char m_pad[0x414];
    int m_field414;
};

int CServer::GetOffset414()
{
    return (int)&m_field414;
}
