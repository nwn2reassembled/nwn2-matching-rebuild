struct Slot
{
    unsigned char before[0x114];
    unsigned char value;
    unsigned char after[0x0F];
};

class Slots
{
public:
    unsigned char Get(unsigned char index);

private:
    Slot m_slots[4];
};

unsigned char Slots::Get(unsigned char index)
{
    if (index >= 4)
        return 0;

    return m_slots[index].value;
}
