struct Inner
{
    int value;
};

struct Outer
{
    int dummy[4];          // offsets 0x00-0x0F
    Inner* ptrAtOffset10; // at offset 0x10
};

class MyStruct
{
public:
    bool test();
};

bool MyStruct::test()
{
    Outer* outer = *reinterpret_cast<Outer**>(0x86442C);
    return (outer->ptrAtOffset10->value == 1);
}

