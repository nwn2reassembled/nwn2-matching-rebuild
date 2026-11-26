struct GameState
{
    char pad00[0x48];
    unsigned int active;
    char pad4C[0x18];
    unsigned int flags;
};

int IsStateReady(const GameState* state)
{
    if (state == 0)
        return 0;
    if (state->active == 0)
        return 0;
    unsigned int mask = state->flags;
    mask &= 0x30;
    return mask == 0x30;
}
