struct CServerObject
{
    unsigned char m_pad0[0x3b0];
    int m_field3b0;
    unsigned char m_pad1[0x184];
    int m_field538;

    bool IsReady() const;
};

bool CServerObject::IsReady() const
{
    return m_field538 != 0 && m_field3b0 != 0;
}
