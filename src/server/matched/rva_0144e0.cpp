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

struct Sandwich
{
    unsigned int prefix;
    Part value;
    unsigned short tail;
    Sandwich();
};

typedef char SandwichSizeMustBeSixteen[(sizeof(Sandwich) == 16) ? 1 : -1];

Sandwich::Sandwich() : prefix(0), tail(0)
{
}
