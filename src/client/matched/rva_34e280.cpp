class CStats {
public:
    unsigned char pad_000[0xC4];
    int field_C4;
};

class CActor {
public:
    void SetFieldC4(int value);
private:
    unsigned char pad_000[0x110];
    CStats* stats;
};

void CActor::SetFieldC4(int value)
{
    CStats* stats = this->stats;
    if (stats != 0) {
        stats->field_C4 = value;
    }
}
