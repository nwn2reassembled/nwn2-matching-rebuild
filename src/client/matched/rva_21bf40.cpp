int __stdcall CheckClassPair(int a, int b)
{
    if (b == 0x11) {
        if (a == 5 || a == 4)
            return 1;
    } else if (b == 0x12) {
        if (a == 7 || a == 6)
            return 1;
    } else if (b == 0x15) {
        if (a == 9 || a == 8)
            return 1;
    } else if (b == 0x14) {
        if (a == 0xd || a == 0xe)
            return 1;
    }
    return 0;
}
