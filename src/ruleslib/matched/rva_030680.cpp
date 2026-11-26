struct FlagRecord {
    unsigned char pad0;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char flag;
};

void __stdcall SetFlag(FlagRecord *rec, unsigned char value)
{
    if (rec != 0) {
        rec->flag = value;
    }
}
