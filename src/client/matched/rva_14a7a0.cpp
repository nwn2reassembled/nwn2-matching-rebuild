struct Foo
{
    char pad0[0xa90];
    int* m_array;
    char padA[4];
    int m_count;
    char padB[0xc28 - 0xa9c];
    int m_index;

    int Next(int* value);
};

int Foo::Next(int* value)
{
    ++m_index;
    if (m_index < m_count)
    {
        *value = m_array[m_index];
        return 1;
    }
    return 0;
}
