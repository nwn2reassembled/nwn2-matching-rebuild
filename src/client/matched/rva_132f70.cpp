struct Foo
{
    int pad[5];
    unsigned char field14;
};

unsigned char GetByteAt14(const struct Foo* p)
{
    return p->field14;
}
