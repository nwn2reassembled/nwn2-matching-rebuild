unsigned char NWNX_RulesSkillCategory(unsigned short nSkill)
{
    if (nSkill >= 0x745 && nSkill < 0x858)
        return 1;
    if (nSkill >= 0x858 && nSkill < 0x8c9)
        return 2;
    return 0;
}
