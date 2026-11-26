struct Target
{
    char padding[0x43c];
    int value;
};

struct Holder
{
    int padding;
    Target* target;

    int GetValue() const;
};

int Holder::GetValue() const
{
    if (target != 0)
        return target->value;

    return 0;
}
