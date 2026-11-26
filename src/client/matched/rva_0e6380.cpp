class Widget {
public:
    char pad0[0x214];
    int **slots;      // +0x214
    char pad1[4];
    int slotCount;    // +0x21c

    int *GetSlot(int index);
};

int *Widget::GetSlot(int index)
{
    if (index < slotCount && index >= 0)
        return slots[index];
    return 0;
}
