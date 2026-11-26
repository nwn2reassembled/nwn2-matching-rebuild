class IndexedArray {
public:
    void* get(int index);

private:
    int m_unknown0;
    void** m_items;
    int m_unknown8;
    int m_limit;
};

void* IndexedArray::get(int index) {
    if (index < m_limit)
        return m_items[index];
    return 0;
}
