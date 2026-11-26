struct Entry {
    int v;
    int pad[2];
};

class thing_t {
public:
    void clear_entries();

private:
    char head[0x1e8];
    Entry groups[6][52];
};

void thing_t::clear_entries()
{
    groups[0][0].v = 0;
    groups[0][1].v = 0;
    groups[0][2].v = 0;
    groups[0][3].v = 0;
    groups[0][4].v = 0;
    groups[0][5].v = 0;
    groups[0][6].v = 0;
    groups[0][7].v = 0;
    groups[0][8].v = 0;
    groups[0][9].v = 0;
    groups[0][10].v = 0;
    groups[1][0].v = 0;
    groups[1][1].v = 0;
    groups[1][2].v = 0;
    groups[1][3].v = 0;
    groups[1][4].v = 0;
    groups[1][5].v = 0;
    groups[1][6].v = 0;
    groups[1][7].v = 0;
    groups[1][8].v = 0;
    groups[1][9].v = 0;
    groups[1][10].v = 0;
    groups[2][0].v = 0;
    groups[2][1].v = 0;
    groups[2][2].v = 0;
    groups[2][3].v = 0;
    groups[2][4].v = 0;
    groups[2][5].v = 0;
    groups[2][6].v = 0;
    groups[2][7].v = 0;
    groups[2][8].v = 0;
    groups[2][9].v = 0;
    groups[2][10].v = 0;
    groups[3][0].v = 0;
    groups[3][1].v = 0;
    groups[3][2].v = 0;
    groups[3][3].v = 0;
    groups[3][4].v = 0;
    groups[3][5].v = 0;
    groups[3][6].v = 0;
    groups[3][7].v = 0;
    groups[3][8].v = 0;
    groups[3][9].v = 0;
    groups[3][10].v = 0;
    groups[4][0].v = 0;
    groups[4][1].v = 0;
    groups[4][2].v = 0;
    groups[4][3].v = 0;
    groups[4][4].v = 0;
    groups[4][5].v = 0;
    groups[4][6].v = 0;
    groups[4][7].v = 0;
    groups[4][8].v = 0;
    groups[4][9].v = 0;
    groups[4][10].v = 0;
    groups[5][0].v = 0;
    groups[5][1].v = 0;
    groups[5][2].v = 0;
    groups[5][3].v = 0;
    groups[5][4].v = 0;
    groups[5][5].v = 0;
    groups[5][6].v = 0;
    groups[5][7].v = 0;
    groups[5][8].v = 0;
    groups[5][9].v = 0;
    groups[5][10].v = 0;
}
