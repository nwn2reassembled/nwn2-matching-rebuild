unsigned int __stdcall ResolveAppearanceIds(unsigned short id, unsigned short* outBase, unsigned short* outOverride)
{
    switch (id)
    {
    case 0x14:
        *outBase = 0x6c1;
        *outOverride = 0x6c7;
        return 1;
    case 0x29:
        *outBase = 0x6c1;
        *outOverride = 0x6c6;
        return 1;
    case 0x1e:
        *outBase = 0x6c2;
        *outOverride = 0x6c3;
        return 1;
    case 0x44b:
        *outBase = 0x6c1;
        *outOverride = 0x6c8;
        return 1;
    case 0x44c:
        *outBase = 0x6c2;
        *outOverride = 0x6c5;
        return 1;
    case 0x44f:
        *outBase = 0x6c2;
        *outOverride = 0x6c4;
        return 1;
    case 0x7b4:
        *outBase = 0x6c1;
        *outOverride = 0x7b5;
        return 1;
    case 0x7b6:
        *outBase = 0x6c2;
        *outOverride = 0x7b7;
        return 1;
    default:
        *outBase = 0xffff;
        *outOverride = 0xffff;
        return 0;
    }
}
