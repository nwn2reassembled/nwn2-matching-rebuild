struct WordList
{
    unsigned short* m_pData;
    int m_nCount;

    int CountMatches(const unsigned short* pValue);
};

int WordList::CountMatches(const unsigned short* pValue)
{
    int nMatches = 0;
    int nCount = m_nCount;

    if (nCount > 0)
    {
        unsigned short* p = m_pData;
        unsigned short value = *pValue;

        do
        {
            if (*p == value)
                ++nMatches;

            ++p;
            --nCount;
        }
        while (nCount != 0);
    }

    return nMatches;
}
