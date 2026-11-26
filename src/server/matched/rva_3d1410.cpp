struct COwner;

struct COther
{
    char m_pad0[0x326];
    unsigned char m_pOwnerStorage[4];
};

struct COwner
{
    char m_pad0[0x1a];
    unsigned char m_pOtherStorage[4];

    void Detach();
};

void COwner::Detach()
{
    COther* other = *reinterpret_cast<COther**>(m_pOtherStorage);
    if (*reinterpret_cast<COwner**>(other->m_pOwnerStorage) == this)
        *reinterpret_cast<COwner**>(other->m_pOwnerStorage) = 0;
}
