// Proposed independent indexed WORD accessor; original declarations unknown.
struct AdjacentCell
{
    unsigned short value;
    unsigned char remainder[10];
};

struct AdjacentGrid
{
    unsigned char prefix[0x1c0];
    AdjacentCell cells[10][10];
    unsigned short getAt(unsigned char row, unsigned char column);
};

typedef char CellSizeCheck[(sizeof(AdjacentCell) == 12) ? 1 : -1];

unsigned short AdjacentGrid::getAt(unsigned char row, unsigned char column)
{
    return cells[row][column].value;
}
