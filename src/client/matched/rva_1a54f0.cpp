typedef unsigned char BYTE_T;

struct CObj {
    BYTE_T m_byData[0xaa4 + 3];

    BYTE_T GetByteByIndex(unsigned char nIndex);
};

BYTE_T CObj::GetByteByIndex(unsigned char nIndex)
{
    if (nIndex < 3)
        return m_byData[0xaa4 + nIndex];
    return 0;
}
