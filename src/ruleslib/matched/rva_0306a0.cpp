struct X
{
    int a;
    int b;
    int c;
};

void __stdcall SetField(X* p, int value)
{
    if (p != 0)
    {
        p->b = value;
    }
}
