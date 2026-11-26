class C
{
public:
    int Get(int index);

private:
    int m_mode;
    union
    {
        int m_value;
        int* m_values;
    } m_data;
    int m_stride;
};

int C::Get(int index)
{
    if (m_mode == 0)
        return m_stride * index + m_data.m_value;

    return m_data.m_values[index];
}
