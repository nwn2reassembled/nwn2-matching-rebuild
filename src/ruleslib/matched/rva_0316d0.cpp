class Foo {
public:
    static void __stdcall setField(void* ptr, unsigned int val);
};

void __stdcall Foo::setField(void* ptr, unsigned int val)
{
    *(unsigned int*)((char*)ptr + 0x614) = val;
}

