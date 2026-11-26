struct S
{
    int a;
    int b;
    S& clear();
};

S& S::clear()
{
    a = 0;
    b = 0;
    return *this;
}
