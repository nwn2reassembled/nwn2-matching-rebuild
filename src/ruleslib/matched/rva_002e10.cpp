/* Positive-return branch hypothesis, equivalent to the retained early-null form.
 * Original declaration and class names remain unknown.
 */
struct PositiveRule {
    unsigned char unknown_00[0x54];
    unsigned int default_flag;
};
struct PositiveRegistry {
    PositiveRule *__thiscall lookup(unsigned short key) const;
};
extern PositiveRegistry *positive_registry;
struct PositiveEntry12 {
    short key;
    unsigned char value;
    unsigned char flags;
    unsigned char unknown_04[8];
};
typedef char require_entry12[(sizeof(PositiveEntry12) == 12) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];
struct PositiveTable12 {
    unsigned char unknown_0000[0x558];
    PositiveEntry12 *entries;
    unsigned short count;
    unsigned int __thiscall flag_or_default(unsigned short key) const;
};

unsigned int __thiscall PositiveTable12::flag_or_default(unsigned short key) const
{
    for (unsigned short index = 0; index < count; ++index) {
        if ((unsigned short)entries[index].key == key)
            return entries[index].flags & 1;
    }
    PositiveRule *entry = positive_registry->lookup(key);
    if (entry != 0)
        return entry->default_flag;
    return 0;
}
