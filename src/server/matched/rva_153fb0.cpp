// Proposed independent count accessor, not recovered original declarations.
struct AdjacentCount16
{
    unsigned int prefix[4];
    unsigned int count;
    unsigned int size();
};

unsigned int AdjacentCount16::size()
{
    return count;
}
