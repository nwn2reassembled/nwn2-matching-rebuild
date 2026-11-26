// Proposed independent indexed BYTE accessor; original declarations unknown.
struct AdjacentByteCell
{
    unsigned char value;
    unsigned char remainder[11];
};

struct AdjacentByteGrid
{
    unsigned char prefix[0x3a0];
    AdjacentByteCell cells[10][10];
    unsigned char getAt(unsigned char row, unsigned char column);
};

typedef char ByteCellSizeCheck[(sizeof(AdjacentByteCell) == 12) ? 1 : -1];

unsigned char AdjacentByteGrid::getAt(unsigned char row, unsigned char column)
{
    return cells[row][column].value;
}
