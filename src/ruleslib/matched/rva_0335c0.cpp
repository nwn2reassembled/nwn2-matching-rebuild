struct ByteHolder
{
    char padding[0x2a];
    unsigned char value;
};

unsigned char __stdcall ReadByte(const ByteHolder* holder)
{
    return holder->value;
}
