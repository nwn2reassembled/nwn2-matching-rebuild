struct Holder
{
    int first;
    int second;
    int Assign(const int* source, int kind);
};

int Holder::Assign(const int* source, int kind)
{
    if (kind != 4)
    {
        return 0;
    }

    second = *source;
    return 1;
}
