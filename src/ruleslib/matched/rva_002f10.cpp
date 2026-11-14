/* Source reconstruction with a genuine external call and global data reference.
 * No original address constants or machine bytes occur in this implementation.
 */
struct RuleEntry180 {
    unsigned char unknown_00[0x54];
    unsigned int default_flag;
    unsigned char unknown_58[0x28];
    int enabled;
    int blocked;
    unsigned char unknown_88[0x2c];
};
struct RuleRegistry {
    unsigned char unknown_000[0x140];
    RuleEntry180 *entries;
    unsigned char unknown_144[0x10];
    unsigned short count;
    RuleEntry180 *__thiscall lookup(unsigned short index) const;
    RuleEntry180 *__thiscall unchecked_at(unsigned short index) const;
};
extern RuleRegistry *rule_registry;

struct FallbackEntry12 {
    short key;
    unsigned char value;
    unsigned char flags;
    unsigned char unknown_04[8];
};
typedef char require_entry12[(sizeof(FallbackEntry12) == 12) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];

struct ElementTableFallback12 {
    unsigned char unknown_0000[0x558];
    FallbackEntry12 *entries;
    unsigned short count;
    unsigned int __thiscall flag_or_default(unsigned short key) const;
    unsigned char __thiscall find_value(short key) const;
};

unsigned int __thiscall ElementTableFallback12::flag_or_default(unsigned short key) const
{
    for (unsigned short index = 0; index < count; ++index) {
        if ((unsigned short)entries[index].key == key)
            return entries[index].flags & 1;
    }
    RuleEntry180 *entry = rule_registry->lookup(key);
    if (entry == 0)
        return 0;
    return entry->default_flag;
}

unsigned char __thiscall ElementTableFallback12::find_value(short key) const
{
    for (unsigned short index = 0; index < count; ++index) {
        if (entries[index].key == key)
            return entries[index].value;
    }
    return 0xff;
}
