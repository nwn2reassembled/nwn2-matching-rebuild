struct Block16
{
    int v[16];
};

struct Source
{
    int a;
    int b;
    int c;
    int d;
    Block16 arr;
    int e;
    char f;
    char g;
};

struct Dest
{
    char pad[512];
    int a;
    int b;
    int c;
    int d;
    Block16 arr;
    int e;
    char f;
    char g;

    Dest* CopyFrom(const Source* src);
};

Dest* Dest::CopyFrom(const Source* src)
{
    a = src->a;
    b = src->b;
    c = src->c;
    d = src->d;
    arr = src->arr;
    e = src->e;
    f = src->f;
    g = src->g;
    return this;
}
