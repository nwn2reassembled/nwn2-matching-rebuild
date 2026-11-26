struct CValueList
{
    unsigned char m_reserved[0xe5c];
    int* m_values;
    int m_reserved2;
    int m_count;

    int GetValue(int index) const;
};

int CValueList::GetValue(int index) const
{
    if (index < 0 || index >= m_count)
        return 0;
    return m_values[index];
}
