class CRules
{
public:
    static const int kMaxLevel = 0x13f;

    int GetMaxLevel() const;
};

int CRules::GetMaxLevel() const
{
    return kMaxLevel;
}
