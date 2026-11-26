struct SlotHolder
{
    unsigned char pad[0x5cb];
    unsigned char slots[9];

    void SetSlot(unsigned char slot, unsigned char value);
};

void SlotHolder::SetSlot(unsigned char slot, unsigned char value)
{
    if (slot < 9)
        slots[slot] = value;
}
