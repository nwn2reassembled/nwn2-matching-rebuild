struct SomeClass
{
    unsigned char pad0[0x234];
    int state;
};

unsigned char __cdecl IsStateNotTwo(SomeClass* self)
{
    return self->state != 2;
}
