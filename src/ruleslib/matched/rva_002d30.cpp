/* Header-free C++03 probe for a lawfully available VC80 toolchain.
 * These are ABI-level reconstructions, not recovered original class names.
 * No inline assembly or original instruction payloads are embedded.
 */
#if defined(_MSC_VER)
#define PROBE_THISCALL __thiscall
#define PROBE_CDECL __cdecl
#else
#define PROBE_THISCALL __attribute__((thiscall))
#define PROBE_CDECL __attribute__((cdecl))
#endif

typedef unsigned int address32;
typedef char require_address32[(sizeof(address32) == 4) ? 1 : -1];
typedef char require_ushort16[(sizeof(unsigned short) == 2) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];

struct ElementAddress12 {
    address32 PROBE_THISCALL at(unsigned int index) const;
};

address32 PROBE_THISCALL ElementAddress12::at(unsigned int index) const
{
    return (address32)this + index * 12u;
}

struct ElementTable12 {
    unsigned char unknown_0000[0x558];
    address32 entries_address;
    unsigned short count;
    address32 PROBE_THISCALL bounded_at(unsigned short index) const;
};

address32 PROBE_THISCALL ElementTable12::bounded_at(unsigned short index) const
{
    if (index < count)
        return entries_address + (unsigned int)index * 12u;
    return 0;
}

extern "C" int PROBE_CDECL ability_modifier(unsigned char score)
{
    if (score < 10)
        return ((int)score - 11) / 2;
    return ((int)score - 10) / 2;
}
