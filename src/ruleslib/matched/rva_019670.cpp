/* Header-free registry lookup reconstructions; names are descriptive hypotheses. */
struct RuleEntry180 {
    unsigned char unknown_00[0x54];
    unsigned int default_flag;
    unsigned char unknown_58[0x28];
    int enabled;
    int blocked;
    unsigned char unknown_88[0x2c];
};
typedef char require_entry180[(sizeof(RuleEntry180) == 0xb4) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];

struct RuleRegistry {
    unsigned char unknown_000[0x140];
    RuleEntry180 *entries;
    unsigned char unknown_144[0x10];
    unsigned short count;
    RuleEntry180 *__thiscall lookup(unsigned short index) const;
    RuleEntry180 *__thiscall unchecked_at(unsigned short index) const;
};

RuleEntry180 *__thiscall RuleRegistry::lookup(unsigned short index) const
{
    if (index >= count)
        return 0;
    RuleEntry180 *entry = entries + index;
    if (entry->blocked != 0 || entry->enabled == 0)
        return 0;
    return entry;
}

RuleEntry180 *__thiscall RuleRegistry::unchecked_at(unsigned short index) const
{
    if (index < count)
        return entries + index;
    return 0;
}
