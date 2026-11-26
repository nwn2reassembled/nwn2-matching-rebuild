struct RuleData
{
    unsigned char reserved[0x156];
    unsigned short value;
};

unsigned short __stdcall ReadRuleValue(const RuleData* data)
{
    return data->value;
}
