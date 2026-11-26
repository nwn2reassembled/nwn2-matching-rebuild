class IntVector {
public:
    int GetAt(int index);

private:
    int m_reserved[37];
    int* m_items;
    int m_extra;
    int m_count;
};

int IntVector::GetAt(int index)
{
    if (m_count > index)
        return m_items[index];

    return 0;
}
