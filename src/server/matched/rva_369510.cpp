// Proposed common C++03 declarations, not recovered original type names.
struct Part
{
    unsigned int first;
    unsigned int second;
    Part();
};

struct Pair
{
    Part first;
    Part second;
    Pair();
};

typedef char PartSizeMustBeEight[(sizeof(Part) == 8) ? 1 : -1];
typedef char PairSizeMustBeSixteen[(sizeof(Pair) == 16) ? 1 : -1];
// End shared declaration contract.

struct OffsetSingle
{
    unsigned int prefix;
    Part value;
    OffsetSingle();
};

typedef char OffsetSingleSizeMustBeTwelve[(sizeof(OffsetSingle) == 12) ? 1 : -1];

OffsetSingle::OffsetSingle()
{
}
