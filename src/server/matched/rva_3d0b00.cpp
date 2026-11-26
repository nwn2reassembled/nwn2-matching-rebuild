struct State
{
    unsigned char bytes[0x40];
};

int __cdecl ResetState(State* state)
{
    unsigned char* p = reinterpret_cast<unsigned char*>(state);
    p[0x10] = 0;
    *reinterpret_cast<unsigned int*>(p + 0x11) = 0;
    *reinterpret_cast<unsigned int*>(p + 0x31) = 0;
    *reinterpret_cast<unsigned int*>(p + 0x35) = 0;
    *reinterpret_cast<unsigned int*>(p + 0x2d) = 0;
    return 0;
}
