struct CNWRules
{
    int           m_nSkillPoints[64];   /* 0x000 */
    int           m_nFeatTable[128];    /* 0x100 */
    int           m_nSpellSchools[8];   /* 0x300 */
    int           m_nSaveThrows[5];     /* 0x320 */
    unsigned char m_bHardcoreRules;     /* 0x334 */
};

void __stdcall SetHardcoreRules(CNWRules *pRules, unsigned char bEnable)
{
    pRules->m_bHardcoreRules = bEnable;
}
