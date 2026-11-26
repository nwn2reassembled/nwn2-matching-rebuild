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

struct FlagPair
{
    unsigned char flag;
    Part first;
    Part second;
    unsigned int count;
    FlagPair();
};

typedef char FlagPairSizeMustBeTwentyFour[(sizeof(FlagPair) == 24) ? 1 : -1];

FlagPair::FlagPair()
{
    flag = 0;
    count = 0;
}
