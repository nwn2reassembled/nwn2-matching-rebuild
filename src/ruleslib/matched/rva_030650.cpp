class SomeClass {
public:
    char b0;
    char b1;
    unsigned char flag2;

    void __stdcall SetFlag2(unsigned char value);
};

void SomeClass::SetFlag2(unsigned char value)
{
    if (this != 0)
        this->flag2 = value;
}
