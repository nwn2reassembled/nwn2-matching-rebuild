/* Reconstructed from instructions at NWN2RulesLib.dll RVA 0x151d0.
 * ABI hypothesis confirmed for this leaf: x86 cdecl, unsigned byte argument
 * in a caller-cleaned stack slot, signed 32-bit result in EAX.
 * No original instruction bytes, assembly, or binary payloads are embedded.
 */
int ability_modifier(unsigned char score)
{
    if (score < 10)
        return ((int)score - 11) / 2;
    return ((int)score - 10) / 2;
}
