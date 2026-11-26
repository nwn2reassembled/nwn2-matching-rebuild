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

struct OtherTripleTail
{
    Part value;
    unsigned int first;
    unsigned int second;
    unsigned int third;
    OtherTripleTail();
};

typedef char OtherTripleTailSizeMustBeTwenty[(sizeof(OtherTripleTail) == 20) ? 1 : -1];

OtherTripleTail::OtherTripleTail() : first(0), second(0), third(0)
{
}
