// Proposed independent field accessor; original names/types are unknown.
struct AdjacentCount
{
    unsigned int prefix[2];
    unsigned int count;
    unsigned int size();
};

unsigned int AdjacentCount::size()
{
    return count;
}
