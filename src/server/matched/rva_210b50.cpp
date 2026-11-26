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

struct Twin
{
    Part first;
    Part second;
    Twin();
};

typedef char TwinSizeMustBeSixteen[(sizeof(Twin) == 16) ? 1 : -1];

Twin::Twin()
{
}
