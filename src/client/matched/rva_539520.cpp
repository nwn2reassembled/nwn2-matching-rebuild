// Reconstructed function at nwn2main.exe RVA 0x539520
// Object pointer arrives in ECX. Reads a pointer field at offset 0x1A, and if a
// dword at offset 0x326 of the pointed-to structure equals this pointer, nulls it.

struct OuterObject
{
    unsigned char pad0[0x1a];   // 0x00..0x19
    unsigned char relatedBytes[4]; // 0x1A: pointer-sized field, byte-aligned
};

struct UnknownObject
{
    unsigned char pad0[0x326];  // 0x00..0x325
    unsigned char ownerBytes[4]; // 0x326: back-reference, byte-aligned
};

void __fastcall ClearOwnerReference(OuterObject* thisPtr)
{
    UnknownObject* related = *reinterpret_cast<UnknownObject**>(thisPtr->relatedBytes);
    if (*reinterpret_cast<OuterObject**>(related->ownerBytes) == thisPtr)
    {
        *reinterpret_cast<OuterObject**>(related->ownerBytes) = 0;
    }
}
