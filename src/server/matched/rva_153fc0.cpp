// Proposed independent two-field reset, not original declarations.
struct AdjacentReset
{
    unsigned char prefix[0x9b0];
    unsigned int first;
    unsigned int second;
    void reset();
};

void AdjacentReset::reset()
{
    first = 0;
    second = 0;
}
