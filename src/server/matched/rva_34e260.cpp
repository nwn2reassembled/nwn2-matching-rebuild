class CIntArray
{
public:
    int Get(int index) const;

private:
    int m_reserved;
    const int* m_data;
    int m_size;
};

int CIntArray::Get(int index) const
{
    if (index < m_size)
        return m_data[index];

    return 0;
}
