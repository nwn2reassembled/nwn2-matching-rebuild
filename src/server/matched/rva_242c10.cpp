struct StatBlock {
    short unknown[13];
    short stats[13];

    int SumStats(int mode);
};

int StatBlock::SumStats(int mode) {
    int i = 0;
    int total = 0;
    const short* p = stats;
    while (i < 13) {
        if (mode == 0 || (i != 1 && i != 0 && i != 2)) {
            if (p[0] > -1) {
                total += p[0];
            }
        }
        ++i;
        ++p;
    }
    return total;
}
