class Foo {
public:
    static void __stdcall setValue(Foo* p, unsigned int val);
};

void Foo::setValue(Foo* p, unsigned int val)
{
    *(unsigned int*)((char*)p + 0x5e0) = val;
}

