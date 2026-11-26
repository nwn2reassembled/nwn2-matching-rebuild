unsigned int __stdcall ResolveVisualModelIds(unsigned short creatureKind, unsigned short *outModelA, unsigned short *outModelB)
{
    switch (creatureKind)
    {
    case 0x14:
        *outModelA = 0x6C1;
        *outModelB = 0x6C7;
        return 1;
    case 0x29:
        *outModelA = 0x6C1;
        *outModelB = 0x6C6;
        return 1;
    case 0x1E:
        *outModelA = 0x6C2;
        *outModelB = 0x6C3;
        return 1;
    case 0x44B:
        *outModelA = 0x6C1;
        *outModelB = 0x6C8;
        return 1;
    case 0x44C:
        *outModelA = 0x6C2;
        *outModelB = 0x6C5;
        return 1;
    case 0x44F:
        *outModelA = 0x6C2;
        *outModelB = 0x6C4;
        return 1;
    case 0x7B4:
        *outModelA = 0x6C1;
        *outModelB = 0x7B5;
        return 1;
    case 0x7B6:
        *outModelA = 0x6C2;
        *outModelB = 0x7B7;
        return 1;
    default:
        *outModelA = 0xFFFF;
        *outModelB = 0xFFFF;
        return 0;
    }
}
