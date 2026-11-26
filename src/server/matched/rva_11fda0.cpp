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

struct TailSingle
{
    Part value;
    unsigned short small;
    unsigned int count;
    TailSingle();
};

typedef char TailSingleSizeMustBeSixteen[(sizeof(TailSingle) == 16) ? 1 : -1];

TailSingle::TailSingle() : small(0), count(0)
{
}
