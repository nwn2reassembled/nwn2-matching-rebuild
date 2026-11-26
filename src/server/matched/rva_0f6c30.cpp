struct FiveInts
{
    int a;
    int b;
    int c;
    int d;
    int e;
    FiveInts& operator=(const FiveInts& other);
};

FiveInts& FiveInts::operator=(const FiveInts& other)
{
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;
    e = other.e;
    return *this;
}
