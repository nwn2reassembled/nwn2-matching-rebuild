struct Holder
{
    unsigned char padding[0x24c];
    unsigned long value;
};

unsigned long __stdcall ReadValue(const Holder* holder)
{
    return holder->value;
}
