struct Entry {
    unsigned char field[10][12];
    unsigned char tail[172];
};

class Widget {
public:
    unsigned char __thiscall GetFieldByte(unsigned char index, unsigned char slot);

private:
    unsigned char gap0[0x14];
    unsigned char count;
    unsigned char gap1[0x1A4 - 0x15];
    Entry entries[1];
};

unsigned char Widget::GetFieldByte(unsigned char index, unsigned char slot)
{
    if (index >= count)
        return 0;
    if (slot >= 10)
        return 0;
    return entries[index].field[slot][0];
}
