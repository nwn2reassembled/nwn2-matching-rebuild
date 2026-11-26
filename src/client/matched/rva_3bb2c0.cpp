struct Foo {
    int    m00;
    int    m04;
    int    m08;
    int    m0C;
    int    m10;
    int    m14;
    char   m18;
    char   pad19[7];
    int    m20;
    int    m24;
    int    m28;
    int    m2C;
    int    m30;
    int    m34;
    char   m38;
    char   pad39[7];
    int    m40;
    char   m44;
    char   pad45[3];
    int    m48;
    int    m4C;
    int    m50;
    int    m54;
    int    m58;

    Foo* Reset();
};

Foo* Foo::Reset()
{
    m04 = 0;
    m08 = 0;
    m00 = 0;
    m0C = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m24 = 0;
    m28 = 0;
    m20 = 0;
    m30 = 0;
    m34 = 0;
    m2C = 0;
    m38 = 0;
    m40 = 1;
    m44 = 0;
    m48 = 0;
    m4C = 0;
    m54 = 0;
    m58 = 0;
    m50 = 0;
    return this;
}
