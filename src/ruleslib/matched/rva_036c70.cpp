struct Holder
{
    char padding[10];
    short value;
};

short __stdcall GetHolderValue(Holder* holder)
{
    return holder->value;
}
