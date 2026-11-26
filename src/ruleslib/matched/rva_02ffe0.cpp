struct RuleValue
{
    unsigned char padding[0x61];
    unsigned char value;
};

unsigned char __stdcall GetRuleValue(const RuleValue* rule)
{
    return rule->value;
}
