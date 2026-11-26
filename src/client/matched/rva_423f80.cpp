struct C {
    char padding[0x134];
    int m_first;
    int m_second;
    bool IsBelowLimit() const;
};

bool C::IsBelowLimit() const {
    int value = m_first;
    if (value >= 28) {
        value = m_second;
        if (value >= 28) {
            value = 28;
        }
    }
    return value < 28;
}
