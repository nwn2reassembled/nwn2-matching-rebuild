struct Holder
{
    char data[0x610];
    int value;
};

void __stdcall SetHolderValue(Holder* holder, int value)
{
    holder->value = value;
}
