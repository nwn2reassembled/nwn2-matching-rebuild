struct SomeStruct
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    SomeStruct& Clear();
};

SomeStruct& SomeStruct::Clear()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return *this;
}
