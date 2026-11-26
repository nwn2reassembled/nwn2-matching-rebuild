struct Inner
{
    char pad[0x9c];
    int value;
};

struct Outer
{
    char pad[0x108];
    Inner* inner;
    int Check();
};

int Outer::Check()
{
    if (inner != 0)
        return inner->value != 0;

    return 0;
}
