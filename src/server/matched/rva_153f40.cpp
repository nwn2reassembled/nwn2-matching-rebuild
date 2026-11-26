// Proposed standalone stride accessor; original declarations are unknown.
struct AdjacentRecord
{
    unsigned char bytes[32];
};

struct AdjacentRecords
{
    AdjacentRecord* records;
    AdjacentRecord* getAt(unsigned int index);
};

typedef char RecordSizeCheck[(sizeof(AdjacentRecord) == 32) ? 1 : -1];

AdjacentRecord* AdjacentRecords::getAt(unsigned int index)
{
    return records + index;
}
