/* Three-argument lookup with explicit byte/word output stores. */
struct DetailEntry12 {
    short key;
    unsigned char value;
    unsigned char flags;
    unsigned char unknown_04[4];
    unsigned short detail;
    unsigned char unknown_0a[2];
};
typedef char require_entry12[(sizeof(DetailEntry12) == 12) ? 1 : -1];
typedef char require_pointer32[(sizeof(void *) == 4) ? 1 : -1];
struct DetailTable12 {
    unsigned char unknown_0000[0x558];
    DetailEntry12 *entries;
    unsigned short count;
    unsigned int __thiscall find_details(short key, unsigned char *value, unsigned short *detail) const;
};

unsigned int __thiscall DetailTable12::find_details(short key, unsigned char *value, unsigned short *detail) const
{
    *value = 0xff;
    *detail = 0xffff;
    for (unsigned short index = 0; index < count; ++index) {
        if (entries[index].key == key) {
            if (entries[index].flags == 0) {
                *value = entries[index].value;
                *detail = entries[index].detail;
                return 1;
            }
            return 0;
        }
    }
    return 0;
}
