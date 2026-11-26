class CThing {
public:
    char pad[0x47C];
    unsigned char m_state;

    int IsStateReady();
};

int CThing::IsStateReady() {
    if (m_state == 1 || m_state == 2)
        return 1;
    return 0;
}
