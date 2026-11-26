struct CVitals {
    unsigned char m_unknown[0x5AC]; // 0x000..0x5AB
    unsigned char m_bCheck;         // 0x5AC
    unsigned char m_pad[0x3];       // 0x5AD..0x5AF
    unsigned char m_bFlag;          // 0x5B0

    void UpdateFlag();
};

void CVitals::UpdateFlag() {
    if (this->m_bCheck != 0) {
        this->m_bFlag = 1;
    }
}
