struct Stats {
    unsigned char pad0[0x61e];
    unsigned short count;
    double value;
};

struct Holder {
    void* unknown;
    Stats* stats;
};

void __cdecl ResetStats(Holder* holder)
{
    holder->stats->value = 1.0;
    holder->stats->count = 0;
}
