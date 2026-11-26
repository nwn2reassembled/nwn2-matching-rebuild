struct Obj
{
    char pad[0x48];
    int value;
};

int GetField48(const Obj* p)
{
    return p->value;
}
