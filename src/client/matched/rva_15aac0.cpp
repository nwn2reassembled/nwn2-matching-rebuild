class C {
    char  pad[0x1A0];
    int*  m_items;   // +0x1A0
    int   m_count;   // +0x1A4
public:
    int GetItem(unsigned int index);
};

int C::GetItem(unsigned int index) {
    unsigned short i = (unsigned short)index;
    if (m_count > 0 && i < m_count)
        return m_items[i];
    return 0;
}
