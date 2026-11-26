class NWN2Rules
{
public:
    enum RulesConstants
    {
        kRulesVersion = 647
    };

    int GetRulesVersion() const;
};

int NWN2Rules::GetRulesVersion() const
{
    return kRulesVersion;
}
