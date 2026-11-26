struct C
{
    int* vptr;
    int value;
    int extra;
    C* init(int x);
};

C* C::init(int x)
{
    vptr = reinterpret_cast<int*>(0x806730);
    value = x;
    extra = 0;
    return this;
}
