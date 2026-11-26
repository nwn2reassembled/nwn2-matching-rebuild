struct SpanEntry {
    int       id;      // +0x00
    int       pad0;    // +0x04
    __int64   range;   // +0x08
    int       flag;    // +0x10
};

int __cdecl SpanEntry_InRange(const SpanEntry *a, const SpanEntry *b)
{
    __int64 diff = a->range - b->range;
    __int64 limit = (__int64)a->id;
    if (diff >= limit && b->flag == 0)
        return 1;
    return 0;
}
