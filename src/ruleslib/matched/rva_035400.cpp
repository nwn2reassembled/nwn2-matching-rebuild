struct SomeObject
{
    unsigned char pad0[12];
    unsigned int fieldC;
};

void __stdcall SetFieldC(SomeObject* obj, unsigned int value)
{
    if (obj != 0)
    {
        obj->fieldC = value;
    }
}
