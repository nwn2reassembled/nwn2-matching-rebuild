struct CIndexRange
{
    int m_reserved0;
    int m_reserved1;
    int m_reserved2;
    int m_reserved3;
    int m_reserved4;
    int m_count;

    int IsValidIndex(int index) const;
};

int CIndexRange::IsValidIndex(int index) const
{
    if (index > 0 && index <= m_count)
        return 1;

    return 0;
}
