struct Thing {
    unsigned char pad[0x14];
    unsigned char flags; // flags at offset 0x14, bit 0x2 tested
};

int IsFlagSet(const Thing* t)
{
    if ((t->flags & 0x2) == 0x2) {
        return 1;
    }
    return 0;
}
