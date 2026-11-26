struct Inner
{
    int reserved[4];
    int* value;
};

struct Outer
{
    int reserved[4];
    Inner* inner;
    int* GetValue();
};

int* Outer::GetValue()
{
    if (inner != 0)
        return inner->value;
    return 0;
}
