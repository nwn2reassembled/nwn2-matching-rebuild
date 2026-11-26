namespace NWN2Rules
{
    enum RulesVersion
    {
        RULES_VERSION_1_06_11 = 0x611
    };

    class RulesManager
    {
    public:
        static int CurrentVersion();
    };

    int RulesManager::CurrentVersion()
    {
        return RULES_VERSION_1_06_11;
    }
}
