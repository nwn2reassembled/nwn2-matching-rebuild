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

struct SeparatedParts
{
    Part first;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    Part second;
    SeparatedParts();
};

typedef char SeparatedPartsSizeMustBeTwentyEight[(sizeof(SeparatedParts) == 28) ? 1 : -1];

SeparatedParts::SeparatedParts()
{
    a = 0;
    b = 0;
    c = 0;
}
