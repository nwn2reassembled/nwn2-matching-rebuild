struct SaveGameMgr {
    char pad0[0x16B8];
    unsigned char field_16B8[3];
    char pad1[0xFF];
    unsigned char field_17BA[3];

    void SetClassLevels(unsigned char index, unsigned char level);
};

void SaveGameMgr::SetClassLevels(unsigned char index, unsigned char level)
{
    if (index < 3) {
        field_16B8[index] = level;
        field_17BA[index] = level;
    }
}
