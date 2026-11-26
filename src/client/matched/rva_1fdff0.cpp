struct CItemList
{
    int m_nUnused0;
    void** m_pItems;
    int m_nUnused8;
    int m_nCount;

    void* GetAt(int nIndex);
};

void* CItemList::GetAt(int nIndex)
{
    if (nIndex < m_nCount)
        return m_pItems[nIndex];
    return 0;
}
