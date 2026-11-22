struct ParamStruct
{
    char pad[0x300];
    unsigned long value;
};

class MyClass
{
public:
    unsigned long getValue(const ParamStruct* p) const;
};

unsigned long MyClass::getValue(const ParamStruct* p) const
{
    return p->value;
}

