struct Holder
{
    unsigned char padding[0x1f0];
    int value;
};

int __stdcall GetValue(Holder* holder)
{
    return holder->value;
}
