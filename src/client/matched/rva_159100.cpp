class CObj {
public:
    char m_pad[0x26c];
    char m_slots[13];

    void SetSlots(unsigned short mask, char value);
};

void CObj::SetSlots(unsigned short mask, char value)
{
    if (value < -100)
        value = -100;
    else if (value > 100)
        value = 100;

    for (int i = 0; i < 13; ++i) {
        if ((mask >> i) & 1) {
            m_slots[i] = value;
            return;
        }
    }
}
