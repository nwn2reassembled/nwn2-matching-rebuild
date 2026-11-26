struct Inner
{
    char padding[0x100f4];
    int value;
};

struct Outer
{
    void* unused;
    Inner* inner;

    void SetValue(int value);
};

void Outer::SetValue(int value)
{
    inner->value = value;
}
