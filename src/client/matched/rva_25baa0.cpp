struct CInner {
    int m_nValue;
    char m_pad0[12];
    unsigned char m_nFlag;
};

struct CMid {
    char m_pad0[8];
    CInner* m_pInner;
};

struct CTop {
    CMid* m_pMid;
};

class CHolder {
public:
    char m_reserved0[0x2350];
    int m_nCompare;
    char m_reserved1[0x64];
    CTop* m_pTop;

    int Check();
};

int CHolder::Check()
{
    if (m_pTop != 0)
    {
        CMid* pMid = m_pTop->m_pMid;
        if (pMid != 0)
        {
            CInner* pInner = pMid->m_pInner;
            if (m_nCompare >= pInner->m_nValue && pInner->m_nFlag == 1)
                return 1;
        }
    }
    return 0;
}
