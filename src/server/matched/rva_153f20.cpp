// Proposed independent adjacent accessor; names and layout are hypotheses.
struct AdjacentTable
{
    unsigned char prefix[0x108];
    unsigned int* table;
    unsigned int getAt(unsigned short index);
};

typedef char AdjacentTableSizeCheck[(sizeof(AdjacentTable) == 0x10c) ? 1 : -1];

unsigned int AdjacentTable::getAt(unsigned short index)
{
    return table[index];
}
