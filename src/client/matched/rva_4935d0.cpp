class IntArray {
    int m_reserved;
    int* m_items;
    int m_count;
public:
    int GetAt(int index) const;
};

int IntArray::GetAt(int index) const {
    if (index < m_count)
        return m_items[index];
    return 0;
}
