// Proposed ordinary C++03 declarations; original names and types are unknown.
struct NeighborWords
{
    unsigned short* words;
    unsigned short* getAt(unsigned int index);
};

unsigned short* NeighborWords::getAt(unsigned int index)
{
    return words + index;
}
