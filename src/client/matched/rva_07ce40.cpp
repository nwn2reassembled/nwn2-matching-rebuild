class CThing {
    unsigned char m_flag;      // +0x00
    unsigned char m_pad0[3];
    unsigned int m_id;         // +0x04
    unsigned char m_pad1[4];
    CThing* m_other;           // +0x0C
    unsigned char m_pad2[68];
    CThing* m_fallback;        // +0x54
public:
    unsigned int GetId();
};

unsigned int CThing::GetId() {
    CThing* target;
    if (m_flag != 0) {
        target = m_other;
    } else {
        target = m_fallback;
    }
    return target->m_id;
}
