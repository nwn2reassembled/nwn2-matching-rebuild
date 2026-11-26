struct RuleRecord
{
    unsigned char padding[0x629];
    unsigned char flag;

    unsigned char __stdcall SetFlag(unsigned char value);
};

unsigned char __stdcall RuleRecord::SetFlag(unsigned char value)
{
    flag = value;
    return value;
}
