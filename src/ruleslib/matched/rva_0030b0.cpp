/* Shared primary-bit check and early secondary returns. Source control flow
 * follows the observed predicates; declarations remain experimental hypotheses.
 */
struct SharedPredicates {
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

unsigned int __thiscall SharedPredicates::accepts(unsigned char primary, unsigned char secondary) const
{
    unsigned char bits = mask;
    unsigned char select = selectors;
    unsigned char chosen;
    if (inclusive == 0) {
        if (select & 2) {
            if (primary == 5) chosen = bits & 16;
            else if (primary == 4) chosen = bits & 8;
            else {
                if (primary != 1) goto exclusion_secondary;
                chosen = bits & 1;
            }
            if (chosen != 0) return 0;
        }
exclusion_secondary:
        if ((select & 1) == 0) return 1;
        if (secondary == 2) {
            if ((bits & 2) == 0) return 1;
        } else if (secondary == 3) {
            if ((bits & 4) == 0) return 1;
        } else {
            if (secondary != 1) return 1;
            if ((bits & 1) == 0) return 1;
        }
        return 0;
    }
    unsigned int result = 0;
    if (select & 2) {
        if (primary == 5) chosen = bits & 16;
        else if (primary == 4) chosen = bits & 8;
        else {
            if (primary != 1) goto inclusion_secondary;
            chosen = bits & 1;
        }
        if (chosen != 0) result = 1;
    }
inclusion_secondary:
    if (select & 1) {
        if (secondary == 2) {
            if ((bits & 2) == 0) return result;
        } else if (secondary == 3) {
            if ((bits & 4) == 0) return result;
        } else {
            if (secondary != 1) return result;
            if ((bits & 1) == 0) return result;
        }
        result = 1;
    }
    return result;
}

bool __thiscall SharedPredicates::active() const
{
    return active_field != 0;
}

bool __thiscall SharedPredicates::scheduled(unsigned char level) const
{
    bool result = false;
    if (first > 0 && level >= first) {
        if ((level - first) % interval == 0)
            result = true;
    }
    return result;
}
