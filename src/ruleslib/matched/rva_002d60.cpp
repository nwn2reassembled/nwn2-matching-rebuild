/* Reconstructed table-search leaves. Original class and field names unknown.
 * Source logic follows the decompilation; no original instruction payloads.
 */
typedef unsigned int address32;
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];

struct Entry12 {
    short key;
    unsigned char value;
    unsigned char flags;
    unsigned char unknown_04[8];
};
typedef char require_entry12[(sizeof(Entry12) == 12) ? 1 : -1];

struct ElementTableSearch12 {
    unsigned char unknown_0000[0x558];
    Entry12 *entries;
    unsigned short count;
    unsigned char __thiscall find_unflagged(short key) const;
    unsigned char __thiscall flag_bit_one(short key) const;
};

unsigned char __thiscall ElementTableSearch12::find_unflagged(short key) const
{
    for (unsigned short index = 0; index < count; ++index) {
        if (entries[index].key == key && entries[index].flags == 0)
            return entries[index].value;
    }
    return 0xff;
}

unsigned char __thiscall ElementTableSearch12::flag_bit_one(short key) const
{
    for (unsigned short index = 0; index < count; ++index) {
        if (entries[index].key == key)
            return (entries[index].flags >> 1) & 1;
    }
    return 0;
}
