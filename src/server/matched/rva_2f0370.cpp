class CObjList {
    int m_pad0;
    CObjList** m_pBegin;
    CObjList** m_pEnd;

public:
    int size() const;
};

int CObjList::size() const {
    if (m_pBegin == 0)
        return 0;
    return (int)(m_pEnd - m_pBegin);
}
