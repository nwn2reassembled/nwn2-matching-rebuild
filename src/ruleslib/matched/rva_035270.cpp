struct ValueHolder
{
    char padding[0x24];
    unsigned short value;
};

unsigned short __stdcall ReadValue(const ValueHolder* holder)
{
    return holder->value;
}
