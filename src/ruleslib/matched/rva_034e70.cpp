struct Foo {
    void bar(unsigned int* p, unsigned char c);
};

void Foo::bar(unsigned int* p, unsigned char c)
{
    ((unsigned char*)p)[0x13] = c;
}

