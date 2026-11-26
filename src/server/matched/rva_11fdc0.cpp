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

struct MixedTail
{
    Part value;
    unsigned short first;
    unsigned char flag;
    unsigned int count;
    unsigned short last;
    MixedTail();
};

typedef char MixedTailSizeMustBeTwenty[(sizeof(MixedTail) == 20) ? 1 : -1];

MixedTail::MixedTail() : first(0), flag(0), count(0), last(0)
{
}
