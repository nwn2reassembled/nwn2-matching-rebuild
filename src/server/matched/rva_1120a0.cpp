struct Thing
{
    char pad[0x108];
    int limit;
    int current;
    int spare;
    int Set(int v);
};

int Thing::Set(int v)
{
    if (v > limit)
        return 0;

    int cur = current;
    if (cur > v)
    {
        int diff = cur - v;
        if (diff > spare)
            return 0;
        current = v;
        spare -= diff;
        return 1;
    }

    spare += v - cur;
    current = v;
    return 1;
}
