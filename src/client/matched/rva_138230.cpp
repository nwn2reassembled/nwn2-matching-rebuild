struct OptionFlags {
    int reserved[0x28];
    int flagA0;
    int flagA4;
    int flagA8;
};

struct GameOptions {
    unsigned char pad[0xac8];
    int enabled;
    int gap;
    int flagA[3];
    int flagB[3];
};

void __cdecl CheckOptions(GameOptions* options, OptionFlags* out, int index)
{
    if (options->enabled != 0) {
        if (options->flagA[index] != 0)
            out->flagA0 = 1;
        if (options->flagB[index] != 0)
            out->flagA4 = 1;
        if (index == 2)
            out->flagA8 = 1;
    }
}
