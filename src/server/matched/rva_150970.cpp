// Proposed ordinary C++03 declarations; original names and types are unknown.
struct NeighborCount
{
    void* storage;
    int capacity;
    int count;
    void clear();
};

typedef char CountOffsetCheck[(sizeof(NeighborCount) == 12) ? 1 : -1];

void NeighborCount::clear()
{
    count = 0;
}
