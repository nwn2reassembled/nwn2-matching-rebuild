enum GameRulesVersion { RULES_VERSION_1_23 = 1258 };

int GetGameRulesVersion(void)
{
    GameRulesVersion version = RULES_VERSION_1_23;
    return version;
}
