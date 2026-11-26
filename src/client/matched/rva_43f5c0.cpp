struct Data
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;

    Data* Clear();
};

Data* Data::Clear()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    return this;
}
