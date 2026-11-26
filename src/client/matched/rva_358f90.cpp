int __stdcall IsSpecialTile(unsigned short tile) {
    if (tile == 0xCE || tile == 0xCF || tile == 0xD0 || tile == 0x106)
        return 1;
    return 0;
}
