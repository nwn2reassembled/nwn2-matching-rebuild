class CIntArray
{
public:
    void Remove(const int& nValue);

private:
    int* m_pData;
    int m_nCount;
};

void CIntArray::Remove(const int& nValue)
{
    int nIndex = 0;

    while (nIndex < m_nCount && m_pData[nIndex] != nValue)
        ++nIndex;

    if (nIndex < m_nCount)
    {
        --m_nCount;

        while (nIndex < m_nCount)
        {
            m_pData[nIndex] = m_pData[nIndex + 1];
            ++nIndex;
        }
    }
}
