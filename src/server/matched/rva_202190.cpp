// Proposed enclosing layout and names, not recovered original types.
struct SentinelQuad
{
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
    SentinelQuad();
};

typedef char SentinelQuadSizeMustBeSixteen[(sizeof(SentinelQuad) == 16) ? 1 : -1];

struct SentinelOwner
{
    SentinelQuad value;
    SentinelOwner();
};

typedef char SentinelOwnerSizeMustBeSixteen[(sizeof(SentinelOwner) == 16) ? 1 : -1];

SentinelOwner::SentinelOwner()
{
}
