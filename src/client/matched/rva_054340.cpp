struct Store
{
    char padding[0x21C0];
    int values[1];

    void SetValue(int index, int value);
};

void Store::SetValue(int index, int value)
{
    if (index != 6)
        values[index] = value;
}
