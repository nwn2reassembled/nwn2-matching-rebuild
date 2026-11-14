class Foo {
public:
    void bar(void* ptr, unsigned short val);
};

void Foo::bar(void* ptr, unsigned short val)
{
    *(unsigned short*)((char*)ptr + 0x7e) = val;
}

