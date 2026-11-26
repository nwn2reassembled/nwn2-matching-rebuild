struct Counter {
    int m_unused;
    int* m_begin;
    int* m_end;
    int size();
};

int Counter::size()
{
    if (m_begin == 0)
        return 0;
    return m_end - m_begin;
}
