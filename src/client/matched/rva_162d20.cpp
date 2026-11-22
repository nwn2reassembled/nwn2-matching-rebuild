struct SomeStruct;

class MyClass
{
public:
    SomeStruct* get_member();
};

SomeStruct* MyClass::get_member()
{
    return reinterpret_cast<SomeStruct*>(reinterpret_cast<char*>(this) + 0x2d4);
}

