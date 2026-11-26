struct Holder
{
    unsigned char padding[0x30];
    unsigned char flag;
    Holder* ClearFlag();
};

Holder* Holder::ClearFlag()
{
    flag = 0;
    return this;
}
