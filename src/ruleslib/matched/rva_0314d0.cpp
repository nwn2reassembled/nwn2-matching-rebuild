struct RulesLibState
{
    unsigned char m_abyData[1525];
    unsigned char m_bDirty;
};

void __stdcall RulesLib_SetDirty(RulesLibState* pState, unsigned char bDirty)
{
    pState->m_bDirty = bDirty;
}
