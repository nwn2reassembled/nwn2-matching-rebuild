int IsPE32Plus(unsigned int moduleBase)
{
    if (*reinterpret_cast<unsigned short*>(moduleBase) != 0x5A4D)
        return 0;

    unsigned int peOffset = *reinterpret_cast<unsigned int*>(moduleBase + 0x3C);
    unsigned int peHeader = moduleBase + peOffset;

    if (*reinterpret_cast<unsigned int*>(peHeader) != 0x00004550)
        return 0;

    unsigned short magic = *reinterpret_cast<unsigned short*>(peHeader + 0x18);
    return magic == 0x10B ? 1 : 0;
}
