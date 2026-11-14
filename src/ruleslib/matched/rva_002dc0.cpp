/* Flag lookup variant: full-width result, inferred from EAX initialization.
 * The decompiler's byte result does not establish the original source type.
 */
struct FlagEntry12 {
    short key;
    unsigned char value;
    unsigned char flags;
    unsigned char unknown_04[8];
};
typedef char require_entry12[(sizeof(FlagEntry12) == 12) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];

struct ElementTableFlag12 {
    unsigned char unknown_0000[0x558];
    FlagEntry12 *entries;
    unsigned short count;
    unsigned int __thiscall flag_bit_one(short key) const;
};

unsigned int __thiscall ElementTableFlag12::flag_bit_one(short key) const
{
    for (unsigned short index = 0; index < count; ++index) {
        if (entries[index].key == key)
            return (entries[index].flags >> 1) & 1;
    }
    return 0;
}
