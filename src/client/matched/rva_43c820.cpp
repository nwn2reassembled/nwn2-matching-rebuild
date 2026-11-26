struct C {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    void Set(int a, int b);
};

void C::Set(int a, int b)
{
    m1c = a;
    m20 = b;
}
