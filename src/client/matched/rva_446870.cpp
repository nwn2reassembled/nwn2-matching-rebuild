struct IntSpan
{
    void* m_owner;
    int* m_begin;
    int* m_end;

    int size() const;
};

int IntSpan::size() const
{
    if (m_begin == 0)
        return 0;

    return m_end - m_begin;
}
