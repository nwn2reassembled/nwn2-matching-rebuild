struct EngineContext {
    unsigned char pad0[0xac8];
    unsigned int active;
};

struct StatBlock {
    unsigned char pad0[0x68];
    unsigned int values[18];
};

int ClearStatsIfActive(EngineContext* ctx, StatBlock* stats)
{
    if (ctx->active != 0) {
        stats->values[0] = 0;
        stats->values[1] = 0;
        stats->values[2] = 0;
        stats->values[3] = 0;
        stats->values[4] = 0;
        stats->values[5] = 0;
        stats->values[6] = 0;
        stats->values[7] = 0;
        stats->values[8] = 0;
        stats->values[9] = 0;
        stats->values[10] = 0;
        stats->values[11] = 0;
        stats->values[12] = 0;
        stats->values[13] = 0;
        stats->values[14] = 0;
        stats->values[15] = 0;
        stats->values[16] = 0;
        stats->values[17] = 0;
    }
    return 1;
}
