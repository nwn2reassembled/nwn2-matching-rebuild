// Proposed independent bounds-checked accessor; original declarations unknown.
struct AdjacentChecked
{
    unsigned int prefix[2];
    unsigned int* table;
    unsigned int unknown;
    int count;
    unsigned int getAt(int index);
};

unsigned int AdjacentChecked::getAt(int index)
{
    if (index < count && index >= 0)
        return table[index];
    return 0x7f000000u;
}
