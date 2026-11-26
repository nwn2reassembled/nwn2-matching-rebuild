int IsPEPlusImage(const void *imageBase)
{
    const unsigned short *dosHeader = static_cast<const unsigned short *>(imageBase);
    if (*dosHeader != 0x5A4D)
        return 0;

    const char *base = static_cast<const char *>(imageBase);
    const unsigned long *peSignature =
        reinterpret_cast<const unsigned long *>(base + *reinterpret_cast<const unsigned long *>(base + 0x3C));
    if (*peSignature != 0x00004550)
        return 0;

    const unsigned short *optionalHeaderMagic =
        reinterpret_cast<const unsigned short *>(reinterpret_cast<const char *>(peSignature) + 0x18);
    return *optionalHeaderMagic == 0x010B ? 1 : 0;
}
