struct Obj
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char f;
    unsigned char pad6;
    unsigned char pad7;
    int value;

    Obj();
};

Obj::Obj()
{
    value = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0xFF;
}
