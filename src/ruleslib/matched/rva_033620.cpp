typedef unsigned char byte;

struct S
{
    byte pad[0x43];
    byte value;
};

unsigned char __stdcall ReadValue(const S* p)
{
    return p->value;
}
