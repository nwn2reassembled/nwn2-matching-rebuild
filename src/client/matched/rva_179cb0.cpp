class CPlayer {
    unsigned char pad0[0x88];
    int values[4];

public:
    int GetValue(unsigned int index) /* thiscall */;
};

int CPlayer::GetValue(unsigned int index)
{
    if (index <= 3) {
        return this->values[index];
    }
    return 0;
}
