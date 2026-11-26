class CPlayer {
public:
    void SetMaxLevel(unsigned int level);
    char pad[0x7ab78];
    unsigned int maxLevel;
};

void CPlayer::SetMaxLevel(unsigned int level) {
    if (level >= 0x60) {
        level = 0x60;
    }
    maxLevel = level;
}
