struct S
{
    char pad[0x108];
    int value;
    int Get() const;
};

int S::Get() const
{
    return value;
}
