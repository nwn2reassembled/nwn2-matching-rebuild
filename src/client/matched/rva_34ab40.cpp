struct Ctx {
    char pad0[0x9ec];
    int value9ec;
    void SetField(int v);
};

void Ctx::SetField(int v)
{
    if (this->value9ec != v)
    {
        this->value9ec = v;
    }
}
