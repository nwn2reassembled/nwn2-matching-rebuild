class IntList {
public:
    bool Remove(const int& value);
private:
    int* m_data;
    int m_capacity;
    int m_count;
};

bool IntList::Remove(const int& value)
{
    for (int i = 0; i < m_count; ++i)
    {
        if (value == m_data[i])
        {
            --m_count;
            for (int j = i; j < m_count; ++j)
                m_data[j] = m_data[j + 1];
            return true;
        }
    }
    return false;
}
