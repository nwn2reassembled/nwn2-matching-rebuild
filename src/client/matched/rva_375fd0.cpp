class C {
public:
    void* Get(unsigned char index);
private:
    char m_pad[0x9ac];
    void** m_table;
    unsigned char m_count;
};

void* C::Get(unsigned char index) {
    if (index < m_count)
        return m_table[index];
    return 0;
}
