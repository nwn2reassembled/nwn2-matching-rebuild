struct RulesInfo {
    int id;
    char pad[8];
    int flags;
    int state;
};

// __cdecl free function: pointer argument stack-passed at [esp+4].
int GetDefaultRulesetId(const RulesInfo* info)
{
    if (info == 0)
        return 0;
    if (info->flags == 0)
        return 0;
    if (info->state != 100)
        return 0;
    return info->id;
}
