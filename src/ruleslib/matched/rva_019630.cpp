/* Source-derived checked/address registry routines. Original declarations/names
 * are unknown. The volatile field and split arithmetic are matching hypotheses,
 * not proof that the original declaration used volatile.
 */
typedef unsigned int address32;
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];
struct CheckedRegistry180 {
    unsigned char unknown_000[0x140];
    volatile address32 entries_address;
    unsigned char unknown_144[0x10];
    unsigned short count;
    address32 __thiscall lookup(unsigned short index) const;
};
struct AddressRegistry180 {
    unsigned char unknown_000[0x140];
    address32 entries_address;
    unsigned char unknown_144[0x10];
    unsigned short count;
    address32 __thiscall unchecked_at(unsigned short index) const;
};

address32 __thiscall CheckedRegistry180::lookup(unsigned short index) const
{
    if (index >= count)
        return 0;
    address32 address = (unsigned int)index * 180u;
    address += entries_address;
    if (*(const int *)(address + 0x84) != 0 || *(const int *)(address + 0x80) == 0)
        return 0;
    return address;
}

address32 __thiscall AddressRegistry180::unchecked_at(unsigned short index) const
{
    if (index < count)
        return entries_address + (unsigned int)index * 180u;
    return 0;
}
