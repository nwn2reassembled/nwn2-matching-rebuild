struct CTarget
{
    char m_pad[0xa4];
    int m_nValue;
};

class COwner
{
public:
    void SetValue(int nValue);
private:
    char m_pad[0x1d8];
    CTarget* m_apTargets[13][3];
};

void COwner::SetValue(int nValue)
{
    CTarget** pTarget = &m_apTargets[0][1];
    for (int nCount = 13; nCount != 0; --nCount)
    {
        if (pTarget[-1] != 0)
            pTarget[-1]->m_nValue = nValue;
        if (pTarget[0] != 0)
            pTarget[0]->m_nValue = nValue;
        if (pTarget[1] != 0)
            pTarget[1]->m_nValue = nValue;
        pTarget += 3;
    }
}
