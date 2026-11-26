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

struct InitializedTriple
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned char firstFlag;
    unsigned char secondFlag;
    unsigned int d;
    unsigned int mode;
    Part first;
    Part second;
    Part third;
    InitializedTriple();
};

typedef char InitializedTripleSizeMustBeFortyEight[(sizeof(InitializedTriple) == 48) ? 1 : -1];

InitializedTriple::InitializedTriple()
    : a(0), b(0), c(0), firstFlag(0), secondFlag(0), d(0), mode(3)
{
}
