struct Copyable {
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    float f5;
    short s0;
    short s1;

    Copyable& operator=(const Copyable& other);
};

Copyable& Copyable::operator=(const Copyable& other)
{
    d0 = other.d0;
    d1 = other.d1;
    d2 = other.d2;
    d3 = other.d3;
    d4 = other.d4;
    d5 = other.d5;
    d6 = other.d6;
    d7 = other.d7;
    d8 = other.d8;

    f0 = other.f0;
    f1 = other.f1;
    f2 = other.f2;
    f3 = other.f3;
    f4 = other.f4;
    f5 = other.f5;

    s0 = other.s0;
    s1 = other.s1;

    return *this;
}
