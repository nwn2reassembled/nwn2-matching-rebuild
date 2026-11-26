struct CObject
{
    char m_reserved[0x208];
    int m_stride;
    int m_padding0[2];
    int* m_values;
    int m_padding1;
    int m_count;

    int GetValue(int first, int second);
};

int CObject::GetValue(int first, int second)
{
    int index = m_stride * second + first;
    if (index < m_count && index >= 0)
        return m_values[index];
    return 0;
}
