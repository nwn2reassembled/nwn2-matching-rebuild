class CValueTable {
public:
    int GetValue(unsigned char index);
private:
    int m_reserved[37];
    int m_values[41];
};

int CValueTable::GetValue(unsigned char index) {
    if (index <= 0x28)
        return m_values[index];
    return 0;
}
