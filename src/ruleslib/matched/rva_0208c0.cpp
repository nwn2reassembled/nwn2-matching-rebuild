struct Element {
    char data[0x32c];
    int flag;
    char pad[8];
};

class MyClass {
public:
    int m_count;
    Element* m_data;
    Element* findByIndex(int idx) const;
};

Element* MyClass::findByIndex(int idx) const {
    if (m_data && idx >= 0 && idx < m_count) {
        Element* ptr = m_data + idx;
        if (ptr->flag == 1)
            return ptr;
    }
    return 0;
}
