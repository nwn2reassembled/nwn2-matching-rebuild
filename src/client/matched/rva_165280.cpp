struct StateHolder
{
    unsigned char reserved[0x100b0];
    unsigned char stateFlags;
    unsigned char GetState();
};

unsigned char StateHolder::GetState()
{
    if ((stateFlags & 2) > 0)
        return 2;

    return (stateFlags & 1) > 0;
}
