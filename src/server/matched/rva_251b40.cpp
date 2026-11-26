struct SomeClass
{
    bool IsFlagSet() const;
};

bool SomeClass::IsFlagSet() const
{
    unsigned char flag = *(unsigned char*)((char*)this + 0x47c);
    return flag == 1 || flag == 2;
}
