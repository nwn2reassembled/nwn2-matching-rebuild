struct Holder
{
    unsigned char padding[0x2B];
    unsigned char field;
};

void __stdcall SetHolderField(Holder* holder, unsigned char value)
{
    holder->field = value;
}
