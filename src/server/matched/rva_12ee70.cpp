struct CPlayer
{
    char pad[0x10];
    int m_characterValue;
};

void SetPlayerCharacterValue(CPlayer *player, int value)
{
    player->m_characterValue = value;
}
