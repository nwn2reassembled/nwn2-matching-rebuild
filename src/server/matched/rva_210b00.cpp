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

struct SentinelQuad
{
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
    SentinelQuad();
};

struct MixedMembers
{
    Part value;
    SentinelQuad first;
    SentinelQuad second;
    MixedMembers();
};

typedef char SentinelQuadSizeMustBeSixteen[(sizeof(SentinelQuad) == 16) ? 1 : -1];
typedef char MixedMembersSizeMustBeForty[(sizeof(MixedMembers) == 40) ? 1 : -1];

MixedMembers::MixedMembers()
{
}
