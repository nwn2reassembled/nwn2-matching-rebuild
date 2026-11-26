struct Holder
{
    char pad[0x5c];
    unsigned short field;
};

unsigned short __stdcall AddWord(Holder* holder, unsigned short value)
{
    holder->field += value;
    return holder->field;
}
