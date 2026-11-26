struct Cell;

class CGrid {
public:
    char pad0[0x18];
    Cell *groups[256];

    Cell *GetCell(unsigned short index);
};

Cell *CGrid::GetCell(unsigned short index)
{
    unsigned char row = (unsigned char)(index >> 8);
    unsigned char col = (unsigned char)index;
    Cell *base = groups[row];

    if (!base || col >= 0x40)
        return 0;

    return (Cell *)((char *)base + col * 0x3c0 + 0x304);
}
