struct IndexedState
{
    char prefix[0x40];
    int values[7];
    unsigned int flags[1];
};

int QueryState(IndexedState* state, int index)
{
    if (state == 0)
        return 0;

    if (state->values[index] == 0)
        return 0;

    return (state->flags[index] & 0x60) != 0;
}
