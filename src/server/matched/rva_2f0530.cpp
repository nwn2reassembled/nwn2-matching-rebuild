struct IntRange {
    int m_nPadding;
    int* m_pBegin;
    int* m_pEnd;
    int GetCount() const;
};

int IntRange::GetCount() const {
    if (m_pBegin == 0) {
        return 0;
    }
    return m_pEnd - m_pBegin;
}
