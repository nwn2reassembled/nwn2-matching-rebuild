struct Entry;

struct EntryList
{
    Entry** m_ppEntries;
    Entry** m_ppEnd;
    unsigned int m_nCount;
};

struct EntryHolder
{
    EntryList* m_pList;
    Entry* GetFirstEntry();
};

Entry* EntryHolder::GetFirstEntry()
{
    if (m_pList->m_nCount <= 0)
        return 0;
    return *m_pList->m_ppEntries;
}
