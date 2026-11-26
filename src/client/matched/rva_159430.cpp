struct Inner
{
    char pad[0xF0];
    int value;
};

struct Outer
{
    char pad[0x108];
    Inner* inner;
    bool Check() const;
};

bool Outer::Check() const
{
    return inner ? inner->value == 1 : false;
}
