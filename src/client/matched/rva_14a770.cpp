struct C
{
    char pad0[0xa90];
    unsigned int* value;
    char pad_value[4];
    unsigned int flag;
    char pad1[0x18c];
    unsigned int other;

    int Func(unsigned int* out);
};

int C::Func(unsigned int* out)
{
    other = 0;
    if (flag == 0)
        return 0;
    *out = *value;
    return 1;
}
