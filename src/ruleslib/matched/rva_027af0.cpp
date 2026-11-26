struct RulesRecord
{
    unsigned int  objectId;         // 0x000
    unsigned int  classMask;        // 0x004
    int           abilityScores[8]; // 0x008
    int           skillRanks[64];   // 0x028
    int           featList[96];     // 0x128
    unsigned char bonusFlags;       // 0x2A8
    unsigned char pendingFlags;     // 0x2A9
    unsigned char levelUpPending;   // 0x2AA
    unsigned char reserved;         // 0x2AB
    bool          dirty;            // 0x2AC

    bool __stdcall IsDirty() const;
};

bool __stdcall RulesRecord::IsDirty() const
{
    return dirty;
}
