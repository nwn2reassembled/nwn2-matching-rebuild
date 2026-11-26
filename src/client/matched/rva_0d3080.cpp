class Probe {
public:
    char pad88[0x88];
    unsigned long m_state;
    char pad8c[5];
    unsigned char m_flag;
    unsigned char __thiscall Check();
};

unsigned char Probe::Check() {
    if (this->m_flag == 0)
        return 0;
    return this->m_state == 2;
}
