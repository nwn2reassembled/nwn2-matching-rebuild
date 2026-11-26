class ServerInfo;

class ServerListEntry
{
public:
    /* ... */
    ServerInfo* GetServerInfo(); /* thiscall, ECX = this */

    /* ... */
    unsigned int m_id;             // 0x00
    unsigned int m_flags;          // 0x04
    void*        m_pField08;       // 0x08
    void*        m_pField0C;       // 0x0C
    void*        m_pField10;       // 0x10
    void*        m_pField14;       // 0x14
    unsigned int m_field18;        // 0x18
    ServerInfo*  m_serverInfo;     // 0x1C
};

ServerInfo* const g_defaultServerInfo = (ServerInfo*)0x0086A640;

ServerInfo* ServerListEntry::GetServerInfo()
{
    ServerInfo* info = this->m_serverInfo;
    if (info == 0)
        info = g_defaultServerInfo;
    return info;
}
