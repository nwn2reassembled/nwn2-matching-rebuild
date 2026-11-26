class ServerObject
{
public:
    char GetType();

    void* m_pData;
};

char ServerObject::GetType()
{
    if (m_pData != 0)
    {
        return *((char*)m_pData + 0x8d);
    }
    return 8;
}
