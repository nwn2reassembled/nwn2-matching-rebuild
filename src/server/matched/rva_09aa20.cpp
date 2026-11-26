class Thing {
    unsigned char m_flag;
    unsigned char pad0[7];
    unsigned int m_valueA;      // offset 0x08
    unsigned char pad1[0x44];
    unsigned int m_valueB;      // offset 0x50
public:
    unsigned int GetSelector() const;
};

unsigned int Thing::GetSelector() const {
    if (this->m_flag != 0) {
        return this->m_valueA;
    }
    return this->m_valueB;
}
