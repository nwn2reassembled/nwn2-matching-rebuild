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

struct SevenParts
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    Part first;
    Part second;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    Part third;
    Part fourth;
    Part fifth;
    Part sixth;
    unsigned char flag;
    Part seventh;
    unsigned int last;
    SevenParts();
};

typedef char SevenPartsSizeMustBeNinetySix[(sizeof(SevenParts) == 96) ? 1 : -1];

SevenParts::SevenParts()
    : a(0), b(1), c(0), d(0), e(0), f(0), g(1), h(1), flag(0), last(0)
{
}
