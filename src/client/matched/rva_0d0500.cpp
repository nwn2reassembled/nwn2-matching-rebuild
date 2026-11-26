struct Obj
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    char m54;
    int m58;

    Obj* Clear();
};

Obj* Obj::Clear()
{
    m00 = 0;
    m04 = 0;
    m08 = 0;
    m0c = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
    return this;
}
