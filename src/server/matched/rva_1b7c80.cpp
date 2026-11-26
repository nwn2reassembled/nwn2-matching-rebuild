class ServerObject {
    char pad[0x63c];
    unsigned char grid[4][10];

public:
    void SetGridCell(unsigned char row, unsigned char col, unsigned char value);
};

void ServerObject::SetGridCell(unsigned char row, unsigned char col, unsigned char value)
{
    if (row < 4 && col < 10) {
        grid[row][col] = value;
    }
}
