/* Cached mask, direct selector-member access. Names/layout declarations remain
 * hypotheses; no assembly, original addresses, instruction bytes or padding.
 */
struct MatchedPredicates {
    unsigned char unknown_000[0xd0];
    int active_field;
    unsigned char unknown_0d4[0x4ea];
    unsigned char mask;
    unsigned char selectors;
    int inclusive;
    unsigned char unknown_5c4[0x64];
    unsigned char first;
    unsigned char interval;
    unsigned int __thiscall accepts(unsigned char primary, unsigned char secondary) const;
    bool __thiscall active() const;
    bool __thiscall scheduled(unsigned char level) const;
};
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];

unsigned int __thiscall MatchedPredicates::accepts(unsigned char primary, unsigned char secondary) const
{
    unsigned char bits = mask;
    unsigned int result = 1;
    if (inclusive == 0) {
        if ((selectors & 2) && ((primary == 5 && (bits & 16)) ||
            (primary == 4 && (bits & 8)) || (primary == 1 && (bits & 1))))
            return 0;
        if ((selectors & 1) && ((secondary == 2 && (bits & 2)) ||
            (secondary == 3 && (bits & 4)) || (secondary == 1 && (bits & 1))))
            return 0;
    } else {
        result = 0;
        if ((selectors & 2) && ((primary == 5 && (bits & 16)) ||
            (primary == 4 && (bits & 8)) || (primary == 1 && (bits & 1))))
            result = 1;
        if ((selectors & 1) && ((secondary == 2 && (bits & 2)) ||
            (secondary == 3 && (bits & 4)) || (secondary == 1 && (bits & 1))))
            result = 1;
    }
    return result;
}

bool __thiscall MatchedPredicates::active() const
{
    return active_field != 0;
}

bool __thiscall MatchedPredicates::scheduled(unsigned char level) const
{
    bool result = false;
    if (first > 0 && level >= first) {
        if ((level - first) % interval == 0)
            result = true;
    }
    return result;
}
