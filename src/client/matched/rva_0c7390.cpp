struct Target
{
    char reserved[0x7c];
    int value;
};

struct Owner
{
    int reserved;
    Target* target;

    void SetValue(int value);
};

void Owner::SetValue(int value)
{
    if (target != 0)
    {
        target->value = value;
    }
}
