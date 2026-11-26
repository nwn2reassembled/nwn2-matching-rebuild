// Proposed packed layout, not recovered original names or declarations.
struct SentinelQuad
{
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
    SentinelQuad();
};

#pragma pack(push, 1)
struct PackedValues
{
    unsigned char flag;
    unsigned int values[8];
};
#pragma pack(pop)

struct PackedOwner
{
    SentinelQuad first;
    SentinelQuad second;
    PackedValues packed;
    unsigned char untouched;
    unsigned short marker;
    unsigned int group[8];
    unsigned int tail0;
    unsigned int tail1;
    unsigned int tail2;
    PackedOwner();
};

typedef char QuadSizeCheck[(sizeof(SentinelQuad) == 16) ? 1 : -1];
typedef char PackedSizeCheck[(sizeof(PackedValues) == 33) ? 1 : -1];
typedef char OwnerSizeCheck[(sizeof(PackedOwner) == 112) ? 1 : -1];

PackedOwner::PackedOwner()
{
    packed.values[0] = 0;
    packed.values[1] = 0;
    packed.values[2] = 0;
    packed.values[3] = 0;
    packed.values[4] = 0;
    packed.values[5] = 0;
    packed.values[6] = 0;
    packed.values[7] = 0;
    group[0] = 0;
    group[1] = 0;
    group[2] = 0;
    group[3] = 0;
    group[4] = 0;
    group[5] = 0;
    group[6] = 0;
    group[7] = 0;
    tail1 = 0;
    tail2 = 0;
    tail0 = 0;
    packed.flag = 0;
    marker = 0xffffu;
}
