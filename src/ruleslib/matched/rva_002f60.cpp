/* Registry-first availability hypothesis. Names/types are descriptive, not
 * recovered declarations. No original addresses, instructions or padding.
 */
struct PositiveRule {
    unsigned char unknown_00[0x54];
    unsigned int default_flag;
};
struct PositiveRegistry {
    PositiveRule *__thiscall lookup(unsigned short key) const;
};
extern PositiveRegistry *positive_registry;
struct RegistryFirstEntry12 {
    unsigned short key;
    unsigned char unknown_02[10];
};
typedef char require_entry12[(sizeof(RegistryFirstEntry12) == 12) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];
struct RegistryFirstTable12 {
    unsigned char unknown_0000[0x558];
    RegistryFirstEntry12 *entries;
    unsigned short count;
    unsigned int __thiscall available(unsigned short key) const;
};

unsigned int __thiscall RegistryFirstTable12::available(unsigned short key) const
{
    PositiveRule *entry = positive_registry->lookup(key);
    if (entry != 0) {
        if (entry->default_flag != 0)
            return 1;
        for (unsigned short index = 0; index < count; ++index) {
            if (entries[index].key == key)
                return 1;
        }
    }
    return 0;
}
