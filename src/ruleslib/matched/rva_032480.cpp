class MyStruct {
public:
    static void __stdcall foo(unsigned char *ptr, unsigned int val);
};

void MyStruct::foo(unsigned char *ptr, unsigned int val)
{
    *(unsigned int *)(ptr + 0x1c) = val;
}

