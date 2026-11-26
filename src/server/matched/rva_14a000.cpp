struct Target
{
    char reserved[0x100e0];
    int value;
};

struct Container
{
    int unknown;
    Target* target;

    void SetValue(int value);
};

void Container::SetValue(int value)
{
    target->value = value;
}
