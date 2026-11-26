struct SessionFrame
{
    char m_pad[0x24];
};

struct Session : SessionFrame
{
    unsigned long GetConnectionId() const;

    unsigned long m_field24; // offset 0x24
};

unsigned long Session::GetConnectionId() const
{
    unsigned long id = m_field24;
    if (id == 0)
        id = 0x86A640;
    return id;
}
