struct Legacy
{
    char pad[0x7AB78];
    int value;
    int getValue() const;
};

int Legacy::getValue() const
{
    return value;
}

