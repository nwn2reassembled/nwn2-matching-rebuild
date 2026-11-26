struct StateHolder
{
    char reserved[0x7a];
    short value;

    char GetState() const;
};

char StateHolder::GetState() const
{
    if (value <= 30)
        return 3;

    if (value >= 70)
        return 2;

    return 1;
}
