/* ABI-level reconstruction of FUN_10004270, RulesLib RVA 0x4270.
 * ECX carries the base address, a caller-provided index is on the stack,
 * and the callee pops that index. The original class/type names are unknown.
 * Unsigned 32-bit address arithmetic preserves x86 wraparound without relying
 * on signed overflow or out-of-object C pointer arithmetic.
 * No reference instructions or assembly are embedded in this implementation.
 */
_Static_assert(sizeof(unsigned int) == 4, "requires 32-bit unsigned int");

unsigned int __attribute__((thiscall))
element_address_12(unsigned int base_address, unsigned int element_index)
{
    return base_address + element_index * 12u;
}
