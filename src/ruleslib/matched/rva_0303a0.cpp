struct Holder
{
    char padding[0x90];
    int value;
};

void __stdcall SetHolderValue(Holder* holder, int value)
{
    holder->value = value;
}
