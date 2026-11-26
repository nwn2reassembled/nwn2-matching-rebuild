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

struct EarlyTriple
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    Part first;
    Part second;
    Part third;
    unsigned int untouched[3];
    unsigned int last;
    EarlyTriple();
};

typedef char EarlyTripleSizeMustBeSeventyTwo[(sizeof(EarlyTriple) == 72) ? 1 : -1];

EarlyTriple::EarlyTriple()
{
    a = 0;
    b = 0;
    d = 0;
    c = 0;
    f = 0;
    e = 0;
    g = 0;
    h = 0;
    last = 0;
}
