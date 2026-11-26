typedef int BOOL;

struct S
{
    int field0;
    int field4;
    unsigned char field8;
    unsigned char pad9[3];
    int fieldC;
    int field10;
    unsigned char field14;
    unsigned char pad15[3];
    int field18;

    BOOL IsEqual(const S& other) const;
};

BOOL S::IsEqual(const S& other) const
{
    return field0 == other.field0
        && field4 == other.field4
        && field8 == other.field8
        && fieldC == other.fieldC
        && field10 == other.field10
        && field14 == other.field14
        && field18 == other.field18;
}
