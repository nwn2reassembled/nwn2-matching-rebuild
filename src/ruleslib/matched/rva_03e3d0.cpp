class NWN2Rule {
public:
    int ruleId;
    int ruleValue;
    void __stdcall SetRuleValue(int newValue);
};

void __stdcall NWN2Rule::SetRuleValue(int newValue)
{
    (void)newValue;
}
