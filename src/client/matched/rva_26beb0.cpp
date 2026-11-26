struct Inner
{
    char pad[0xbc];
    int value;
};

struct Outer
{
    char pad[0x108];
    Inner* inner;

    void Set(int oldValue, int newValue);
};

void Outer::Set(int oldValue, int newValue)
{
    Inner* p = this->inner;
    if (p != 0 && p->value == oldValue)
    {
        p->value = newValue;
    }
}
