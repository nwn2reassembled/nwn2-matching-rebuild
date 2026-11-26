struct C
{
    int GetValue(int index);

    unsigned char pad0[0x110];
    int* value0;
    unsigned char pad1[8];
    int* value1;
};

int C::GetValue(int index)
{
    if (index == 0)
        return *value0;
    if (index == 1)
        return *value1;
    return 0;
}
