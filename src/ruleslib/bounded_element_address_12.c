/* ABI-level reconstruction of FUN_10002d30, RulesLib RVA 0x2d30.
 * Original class names are unknown. Only assembly-supported fields are named.
 * The unsigned-short argument is compared to an unsigned-short count. No array
 * element is dereferenced: the function returns a computed 32-bit address or 0.
 */
struct ElementTable12 {
    unsigned char unknown_0000[0x558];
    unsigned int entries_address;
    unsigned short count;
};

_Static_assert(sizeof(unsigned int) == 4, "requires 32-bit unsigned int");
_Static_assert(sizeof(unsigned short) == 2, "requires 16-bit unsigned short");
_Static_assert(__builtin_offsetof(struct ElementTable12, entries_address) == 0x558,
               "incorrect entries_address offset");
_Static_assert(__builtin_offsetof(struct ElementTable12, count) == 0x55c,
               "incorrect count offset");

unsigned int __attribute__((thiscall))
bounded_element_address_12(const struct ElementTable12 *table, unsigned short index)
{
    if (index < table->count)
        return table->entries_address + (unsigned int)index * 12u;
    return 0;
}
