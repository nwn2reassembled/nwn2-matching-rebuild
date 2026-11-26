class CGameObject
{
public:
    int GetField3C();

    unsigned int m_flags;
    unsigned char pad[0x38];
    int m_value3C;
};

int CGameObject::GetField3C()
{
    return m_value3C;
}
