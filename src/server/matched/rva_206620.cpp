struct Element;

class ElementList {
public:
    Element* Get(int index);
private:
    char m_reserved[0xe5c];
    Element** m_elements;
    unsigned int m_capacity;
    int m_count;
};

Element* ElementList::Get(int index) {
    if (index >= 0 && index < m_count)
        return m_elements[index];
    return 0;
}
