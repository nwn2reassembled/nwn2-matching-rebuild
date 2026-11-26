// Proposed independent signed-positive predicate; original declarations unknown.
struct AdjacentPredicate
{
    unsigned int prefix[2];
    int count;
    unsigned int hasItems();
};

unsigned int AdjacentPredicate::hasItems()
{
    return count > 0;
}
